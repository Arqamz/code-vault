#include <iostream>
#include <climits>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

vector<vector<pii>> graph; // Adjacency list representation of the graph

vector<int> prim(int start) {
    int n = graph.size();
    vector<int> dist(n, INT_MAX); // Distance of each vertex from the MST
    vector<bool> visited(n, false); // Track visited vertices
    vector<int> parent(n, -1); // Parent of each vertex in the MST

    priority_queue<pii, vector<pii>, greater<pii>> pq; // Min-heap to store vertices based on their distance

    dist[start] = 0; // Start vertex has distance 0
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        visited[u] = true;

        for (auto& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;

            if (!visited[v] && weight < dist[v]) {
                dist[v] = weight;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    return parent;
}

int main() {
    int n, m;
    cin >> n >> m; // Number of vertices and edges

    graph.resize(n);

    for (int i = 0; i < m; i++) {
        int u, v, weight;
        cin >> u >> v >> weight; // Read edge (u, v) with weight

        graph[u].push_back({v, weight});
        graph[v].push_back({u, weight});
    }

    int start;
    cin >> start; // Starting vertex for MST

    vector<int> parent = prim(start);

    cout << "Minimum Spanning Tree:" << endl;
    for (int i = 0; i < n; i++) {
        if (parent[i] != -1) {
            cout << parent[i] << " - " << i << endl;
        }
    }

    return 0;
}