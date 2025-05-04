/*program to implement Graph ADT with an adjacency matrix. The Graph ADT has the following operations,
1. Insert
2. Delete
3. Search
4. Display
5. Exit
*/

#include <iostream>
using namespace std;

#define MAX 100

class Graph {
private:
    int adjMatrix[MAX][MAX];
    int numVertices;

public:
    Graph(int vertices) {
        numVertices = vertices;

        for (int i = 0; i < numVertices; i++)
            for (int j = 0; j < numVertices; j++)
                adjMatrix[i][j] = 0;
    }

    void insertEdge(int src, int dest) {
        if (src >= numVertices || dest >= numVertices || src < 0 || dest < 0) {
            cout << "Invalid edge!\n";
            return;
        }
        adjMatrix[src][dest] = 1;
        adjMatrix[dest][src] = 1;
        cout << "Edge inserted.\n";
    }

    void deleteEdge(int src, int dest) {
        if (src >= numVertices || dest >= numVertices || src < 0 || dest < 0) {
            cout << "Invalid edge!\n";
            return;
        }
        adjMatrix[src][dest] = 0;
        adjMatrix[dest][src] = 0; 
        cout << "Edge deleted.\n";
    }

    void searchEdge(int src, int dest) {
        if (src >= numVertices || dest >= numVertices || src < 0 || dest < 0) {
            cout << "Invalid vertices!\n";
            return;
        }
        if (adjMatrix[src][dest])
            cout << "Edge exists between " << src << " and " << dest << ".\n";
        else
            cout << "No edge exists between " << src << " and " << dest << ".\n";
    }

    void display() {
        cout << "Adjacency Matrix:\n";
        for (int i = 0; i < numVertices; i++) {
            for (int j = 0; j < numVertices; j++)
                cout << adjMatrix[i][j] << " ";
            cout << endl;
        }
    }
};

int main() {
    int vertices, choice, src, dest;

    cout << "Enter number of vertices: ";
    cin >> vertices;

    Graph g(vertices);

    do {
        cout << "\n--- Graph Menu ---\n";
        cout << "1. Insert Edge\n";
        cout << "2. Delete Edge\n";
        cout << "3. Search Edge\n";
        cout << "4. Display Graph\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter source and destination: ";
            cin >> src >> dest;
            g.insertEdge(src, dest);
            break;
        case 2:
            cout << "Enter source and destination: ";
            cin >> src >> dest;
            g.deleteEdge(src, dest);
            break;
        case 3:
            cout << "Enter source and destination: ";
            cin >> src >> dest;
            g.searchEdge(src, dest);
            break;
        case 4:
            g.display();
            break;
        case 5:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 5);

    return 0;
}
