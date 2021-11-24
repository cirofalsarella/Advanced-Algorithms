#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace :: std;


class UnionFind {
	private: 
		typedef vector<int> vi;
		vi p; 
		vi rank;

	public: 

		UnionFind(int N){
			rank.assign(N, 0);  p.assign(N, 0);
			for(int i =0; i<N; i++) p[i] = i;
            // Initialy every node is a tree
		}

		int findSet(int i){
			if (p[i] == i)  return i;   // Root (father of himSelf)
			return findSet(p[i]);
		}

		int unionSet(int i, int j, int w){
            int x = findSet(i);
            int y = findSet(j);

			if (x != y){
				if (rank[x] > rank[y])  p[y] = x;

				else {
					p[x] = y;
					if (rank[x] == rank[y])
						rank[y] = rank[y]+1;
				}

				return w;
			}

			return 0;
		}
};

bool isTree(int nodesNum, vector <vector<int>> graph, int origin) {
    bool visited[nodesNum] = { false };
    queue<int> toVisit;
    toVisit.push(origin);

    while (!toVisit.empty()) {
        // Visit next node
        int node = toVisit.front();
        toVisit.pop();

        if (visited[node])  continue;
        visited[node] = true;

		// Set path to adjascent nodes
        for (int adj : graph[node])	toVisit.push(adj);
    }

    for (int i=0; i<nodesNum; i++) {
        if (!visited[i])    return false;
    }

    return true;
}

int kruskal(vector< pair<int, pair<int,int> > > edges,int origin, int n_edges, int n_nodes) {
	UnionFind tree(n_nodes);	// Creates Tree
    sort(edges.begin(), edges.end());

	int costMin = 0;
	for (int i = 0; i < n_edges; i++){
		pair<int, pair<int, int>> node = edges[i];
		int w = node.first;
		int u = node.second.first;
		int v = node.second.second;

        costMin += tree.unionSet(u, v, w);
	}

    return costMin;
}

int main() {
    int n_nodes, n_edges;   cin >> n_nodes >> n_edges;
    while (n_nodes != 0) {
        // Save the id into a hashmap
        map <string, int> dict;
        for (int i=0; i<n_nodes; i++) {
            string city;    cin >> city;
            dict[city] = i;
        }

        // Save the edges into a array of arrays
        vector < pair<int, pair<int, int> > > edges;
        vector < vector<int> > graph(n_nodes);
        for (int i=0; i<n_edges; i++) {
            string u, v;
            int w;
            cin >> u >> v >> w;
            
            edges.push_back({w, {dict[u], dict[v]}});
            graph[dict[v]].push_back(dict[u]);
            graph[dict[u]].push_back(dict[v]);
        }


        string origin;  cin >> origin;
		if (isTree(n_nodes, graph, dict[origin])) {
			cout << kruskal(edges, dict[origin], n_edges, n_nodes) << endl;
		} else {
			cout << "Impossible" << endl;
		}

        // Next test case
        cin >> n_nodes >> n_edges;
    }
}