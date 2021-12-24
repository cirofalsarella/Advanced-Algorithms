#include <iostream>
#include <climits>
#include <cstring>
#include <vector>
#include <queue>

using namespace :: std;

#define MAX_NODE_QTD 105
int residualGraph[MAX_NODE_QTD][MAX_NODE_QTD];

bool hasPath(int s, int t, int n_nodes, int path[]) {
    int visited[MAX_NODE_QTD] = { false };
    queue<int> toVisit;
    toVisit.push(s);

    while (!toVisit.empty()) {
        int node = toVisit.front();
        toVisit.pop();

        if (node == t)      return true;

        for (int edge=0; edge<n_nodes+1; edge++) {
            int weight = residualGraph[node][edge];

            if (weight > 0 && !visited[edge]) {
                visited[edge] = true;
                toVisit.push(edge);
                path[edge] = node;

                if (edge == t)   return true;
            }
        }
    }

    return false;
}

int EK(int source, int sinc, int n_nodes) {
    int path[n_nodes];

    int maxFlow = 0;
    while (hasPath(source, sinc, n_nodes, path)) {
        int cut = INT_MAX;

        // Calculates the flow cut
        for (int at = sinc; at != source; at = path[at]) {
            int father = path[at];
            cut = min(cut, residualGraph[father][at]);
        }

        // Removes the cut from the flow
        for (int at = sinc; at != source; at = path[at]) {
            int father = path[at];
            residualGraph[father][at] -= cut;
            residualGraph[at][father] += cut;
        }

        maxFlow += cut;
    }

    return maxFlow;
}

int main() {
    int n_nodes;    cin >> n_nodes;
    int networkCount = 1;

    while (n_nodes != 0) {
        int source, sinc;
        cin >> source >> sinc;

        int n_edges;
        cin >> n_edges;

        for (int i=0; i<n_edges; i++) {
            int origin, destiny, flow;   cin >> origin >> destiny >> flow;
            residualGraph[origin][destiny] += flow;
            residualGraph[destiny][origin] += flow;
        }

        cout << "Network " << networkCount << endl;
        cout << "The bandwidth is " << EK(source, sinc, n_nodes) << "." << endl;
        cout << endl;

        // Prepair for next testCase
        memset(residualGraph, 0, sizeof(residualGraph));
        cin >> n_nodes;
        networkCount++;
    }

    return 0;
}