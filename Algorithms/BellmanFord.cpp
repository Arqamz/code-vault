#include <iostream>
#include <vector>
#include <climits>

struct Edge {
    int source, destination, weight;
};

void bellmanFord(std::vector<Edge>& edges, int numVertices, int source) {
    std::vector<int> distance(numVertices, INT_MAX);
    distance[source] = 0;

    for (int i = 1; i <= numVertices - 1; ++i) {
        for (const auto& edge : edges) {
            int u = edge.source;
            int v = edge.destination;
            int w = edge.weight;

            if (distance[u] != INT_MAX && distance[u] + w < distance[v]) {
                distance[v] = distance[u] + w;
            }
        }
    }

    // Check for negative-weight cycles
    for (const auto& edge : edges) {
        int u = edge.source;
        int v = edge.destination;
        int w = edge.weight;

        if (distance[u] != INT_MAX && distance[u] + w < distance[v]) {
            std::cout << "Graph contains negative-weight cycle\n";
            return;
        }
    }

    // Print the distances
    std::cout << "Vertex\tDistance from Source\n";
    for (int i = 0; i < numVertices; ++i) {
        std::cout << i << "\t" << distance[i] << "\n";
    }
}

int main() {
    int numVertices, numEdges;
    std::cout << "Enter the number of vertices: ";
    std::cin >> numVertices;
    std::cout << "Enter the number of edges: ";
    std::cin >> numEdges;

    std::vector<Edge> edges(numEdges);
    std::cout << "Enter the source, destination, and weight of each edge:\n";
    for (int i = 0; i < numEdges; ++i) {
        std::cin >> edges[i].source >> edges[i].destination >> edges[i].weight;
    }

    int source;
    std::cout << "Enter the source vertex: ";
    std::cin >> source;

    bellmanFord(edges, numVertices, source);

    return 0;
}