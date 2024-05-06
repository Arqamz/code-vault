#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii;

vector<int> dijkstra(vector<vector<pii>>& graph, int source) {
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    dist[source] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) {
            continue;
        }

        for (auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int w = neighbor.second;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pii>> graph(n);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    int source;
    cin >> source;

    vector<int> dist = dijkstra(graph, source);

    cout << "Shortest distances from source " << source << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "Vertex " << i << ": " << dist[i] << "\n";
    }

    return 0;
}