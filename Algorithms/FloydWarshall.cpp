#include <iostream>
#include <vector>
#include <climits>

void floydWarshall(std::vector<std::vector<int>>& graph) {
    int V = graph.size();

    // Initialize the distance matrix with the graph
    std::vector<std::vector<int>> dist = graph;

    // Update the distance matrix by considering all vertices as intermediate vertices
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                // If vertex k is on the shortest path from i to j, then update the value of dist[i][j]
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    // Print the shortest distances between every pair of vertices
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (dist[i][j] == INT_MAX) {
                std::cout << "INF ";
            } else {
                std::cout << dist[i][j] << " ";
            }
        }
        std::cout << std::endl;
    }
}

int main() {
    int V, E;
    std::cin >> V >> E;

    // Create a graph represented as an adjacency matrix
    std::vector<std::vector<int>> graph(V, std::vector<int>(V, INT_MAX));

    // Read the edges of the graph
    for (int i = 0; i < E; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        graph[u][v] = w;
    }

    // Run the Floyd-Warshall algorithm
    floydWarshall(graph);

    return 0;
}