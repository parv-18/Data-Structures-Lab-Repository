/* program to implement Graph ADT with the implementation for Prim’s algorithm, Kruskal’s algorithm, and Dijkstra’s algorithm.*/
#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

#define INF INT_MAX

class Graph {
    int V;
    vector<vector<int>> adjMatrix;

public:
    Graph(int V) {
        this->V = V;
        adjMatrix.resize(V, vector<int>(V, 0));
    }

    void addEdge(int u, int v, int w) {
        if (u < 0 || v < 0 || u >= V || v >= V) {
            cout << "Invalid edge.\n";
            return;
        }
        adjMatrix[u][v] = w;
        adjMatrix[v][u] = w;
    }

    void display() {
        cout << "Adjacency Matrix:\n";
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++)
                cout << (adjMatrix[i][j] ? adjMatrix[i][j] : 0) << "\t";
            cout << "\n";
        }
    }

    //Prim's algorithm
    void primMST() {
        vector<int> key(V, INF);
        vector<bool> inMST(V, false);
        vector<int> parent(V, -1);
        key[0] = 0;

        for (int count = 0; count < V - 1; count++) {
            int u = -1;
            int minKey = INF;

            for (int v = 0; v < V; v++) {
                if (!inMST[v] && key[v] < minKey) {
                    minKey = key[v];
                    u = v;
                }
            }

            if (u == -1) return;
            inMST[u] = true;

            for (int v = 0; v < V; v++) {
                if (adjMatrix[u][v] && !inMST[v] && adjMatrix[u][v] < key[v]) {
                    key[v] = adjMatrix[u][v];
                    parent[v] = u;
                }
            }
        }

        cout << "Prim's MST:\n";
        for (int i = 1; i < V; i++)
            cout << parent[i] << " - " << i << " : " << adjMatrix[i][parent[i]] << "\n";
    }

    struct Edge {
        int u, v, w;
    };

    int find(vector<int>& parent, int i) {
        if (parent[i] != i)
            parent[i] = find(parent, parent[i]);
        return parent[i];
    }

    void unionSet(vector<int>& parent, vector<int>& rank, int x, int y) {
        int xroot = find(parent, x);
        int yroot = find(parent, y);

        if (rank[xroot] < rank[yroot])
            parent[xroot] = yroot;
        else if (rank[xroot] > rank[yroot])
            parent[yroot] = xroot;
        else {
            parent[yroot] = xroot;
            rank[xroot]++;
        }
    }

    //Kruskal's algorithm
    void kruskalMST() {
        vector<Edge> edges;
        for (int i = 0; i < V; i++)
            for (int j = i + 1; j < V; j++)
                if (adjMatrix[i][j])
                    edges.push_back({i, j, adjMatrix[i][j]});

        sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
            return a.w < b.w;
        });

        vector<int> parent(V), rank(V, 0);
        for (int i = 0; i < V; i++) parent[i] = i;

        cout << "Kruskal's MST:\n";
        int e = 0;
        for (auto edge : edges) {
            int u = edge.u, v = edge.v, w = edge.w;
            int set_u = find(parent, u);
            int set_v = find(parent, v);

            if (set_u != set_v) {
                cout << u << " - " << v << " : " << w << "\n";
                unionSet(parent, rank, set_u, set_v);
                e++;
                if (e == V - 1) break;
            }
        }
    }

    //Dijkstra's algorithm
    void dijkstra(int src) {
        vector<int> dist(V, INF);
        vector<bool> visited(V, false);
        dist[src] = 0;

        for (int count = 0; count < V - 1; count++) {
            int u = -1;
            int minDist = INF;
            for (int v = 0; v < V; v++)
                if (!visited[v] && dist[v] < minDist) {
                    minDist = dist[v];
                    u = v;
                }

            if (u == -1) break;
            visited[u] = true;

            for (int v = 0; v < V; v++)
                if (!visited[v] && adjMatrix[u][v] && dist[u] + adjMatrix[u][v] < dist[v])
                    dist[v] = dist[u] + adjMatrix[u][v];
        }

        cout << "Dijkstra's Shortest Paths from " << src << ":\n";
        for (int i = 0; i < V; i++)
            cout << "To " << i << " : " << (dist[i] == INF ? -1 : dist[i]) << "\n";
    }
};

int main() {
    int V, choice, u, v, w, src;

    cout << "Enter number of vertices: ";
    cin >> V;
    Graph g(V);

    do {
        cout << "\n--- Graph Algorithms Menu ---\n";
        cout << "1. Add Edge\n";
        cout << "2. Display Graph\n";
        cout << "3. Prim's Algorithm\n";
        cout << "4. Kruskal's Algorithm\n";
        cout << "5. Dijkstra's Algorithm\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter source, destination, and weight: ";
            cin >> u >> v >> w;
            g.addEdge(u, v, w);
            break;
        case 2:
            g.display();
            break;
        case 3:
            g.primMST();
            break;
        case 4:
            g.kruskalMST();
            break;
        case 5:
            cout << "Enter source vertex for Dijkstra's: ";
            cin >> src;
            g.dijkstra(src);
            break;
        case 6:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}
