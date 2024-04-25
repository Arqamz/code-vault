#include <iostream>
#include <vector>

using namespace std;

class Graph {
private:
    vector<vector<int>> adjMatrix;
    int numVertices;

public:
    Graph(int numVertices) {
        this->numVertices = numVertices;
        adjMatrix.resize(numVertices, vector<int>(numVertices, 0));
    }

    void addEdge(int i, int j) {
        if (i >= 0 && i < numVertices && j > 0 && j < numVertices) {
            adjMatrix[i][j] = 1;
            adjMatrix[j][i] = 1;
        }
    }

    void removeEdge(int i, int j) {
        if (i >= 0 && i < numVertices && j > 0 && j < numVertices) {
            adjMatrix[i][j] = 0;
            adjMatrix[j][i] = 0;
        }
    }

    bool isEdge(int i, int j) {
        if (i >= 0 && i < numVertices && j > 0 && j < numVertices)
            return adjMatrix[i][j];
        else
            return false;
    }

    void printMatrix() {
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++)
                cout << adjMatrix[i][j] << " ";
            cout << endl;
        }
    }
};