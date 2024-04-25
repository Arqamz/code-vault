#include <iostream>
#include <vector>

using namespace std;

class Graph {
public:
    Graph(int V) : V(V), adj(new vector<int>[V]) {}

    ~Graph() {
        delete[] adj;
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);
        adj[w].push_back(v);
    }

    void printGraph() {
        for (int v = 0; v < V; ++v) {
            cout << "\n Adjacency list of vertex " << v << "\n head ";
            for (auto x : adj[v])
                cout << "-> " << x;
            cout << endl;
        }
    }

private:
    int V;
    vector<int>* adj;
};

int main() {
    int V = 5;
    Graph graph(V);
    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    graph.printGraph();

    return 0;
}