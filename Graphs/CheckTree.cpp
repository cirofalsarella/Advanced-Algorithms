#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace :: std;

bool isTree(int nodesNum, vector <vector<int>> graph) {
    if (nodesNum == 0)  return true;

    bool visited[nodesNum] = { false };
    queue< pair<int, int> > toVisit;
    toVisit.push({0, 0});

    while (!toVisit.empty()) {
        // Visit next node
        int father = toVisit.front().first;
        int node = toVisit.front().second;
        toVisit.pop();

        if (visited[node])  return false;
        visited[node] = true;

        for (int adj : graph[node]) {
            if (adj != father) {
                toVisit.push({node, adj});
            } else if (adj == node)    return false;
        }
    }

    for (int i=0; i<nodesNum; i++) {
        if (!visited[i])    return false;
    }

    return true;
}

int main() {
    string v, u;   cin >> v >> u;
    int testCase = 1;
    
    while (v[0] != '-' && u[0] != '-') {
        // Save the id into a hashmap
        vector <vector<int>> graph;
        map <string, int> dict;
        int nextId = 0;

        while (v != "0" && u != "0") {
            // If is new, create new edge
            if (dict.find(v) == dict.end()) {
                dict[v] = nextId;
                graph.push_back(vector<int>());
                nextId++;
            }
            if (dict.find(u) == dict.end()){
                dict[u] = nextId;
                graph.push_back(vector<int>());
                nextId++;
            }

            // Add new edge to the graph
            int id_v = dict[v];
            int id_u = dict[u];
            graph[id_v].push_back(id_u);
            graph[id_u].push_back(id_v);
            
            cin >> v >> u;
        }

        if (isTree(nextId, graph)) {
            cout << "Case " << testCase << " is a tree." << endl;
        } else {
            cout << "Case " << testCase << " is not a tree." << endl;
        }

        cin >> v >> u;
        testCase++;
    }
}