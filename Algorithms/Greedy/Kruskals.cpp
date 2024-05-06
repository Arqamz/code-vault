#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Structure to represent a disjoint set
struct DisjointSet {
    vector<int> parent, rank;
    
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        
        // Initialize each element as a separate set
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    // Find the parent of a set
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    
    // Union of two sets
    void unionSets(int x, int y) {
        int xRoot = find(x);
        int yRoot = find(y);
        
        if (rank[xRoot] < rank[yRoot]) {
            parent[xRoot] = yRoot;
        } else if (rank[xRoot] > rank[yRoot]) {
            parent[yRoot] = xRoot;
        } else {
            parent[yRoot] = xRoot;
            rank[xRoot]++;
        }
    }
};

// Function to compare edges by their weight
bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

// Function to find the minimum spanning tree using Kruskal's algorithm
vector<Edge> kruskalsAlgorithm(vector<Edge>& edges, int n) {
    // Sort the edges in non-decreasing order of their weight
    sort(edges.begin(), edges.end(), compareEdges);
    
    vector<Edge> mst; // Minimum Spanning Tree
    DisjointSet ds(n);
    
    for (const auto& edge : edges) {
        int src = edge.src;
        int dest = edge.dest;
        
        // Check if including this edge forms a cycle
        if (ds.find(src) != ds.find(dest)) {
            mst.push_back(edge);
            ds.unionSets(src, dest);
        }
    }
    
    return mst;
}

int main() {
    int n, m; // Number of vertices and edges
    cin >> n >> m;
    
    vector<Edge> edges(m);
    
    for (int i = 0; i < m; i++) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }
    
    vector<Edge> mst = kruskalsAlgorithm(edges, n);
    
    cout << "Minimum Spanning Tree:" << endl;
    for (const auto& edge : mst) {
        cout << edge.src << " - " << edge.dest << " : " << edge.weight << endl;
    }
    
    return 0;
}