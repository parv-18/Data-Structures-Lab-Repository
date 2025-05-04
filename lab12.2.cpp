/* program to implement Graph ADT with an adjacency list. The Graph ADT has the following operations,
1. Insert
2. Delete
3. Search
4. Display
5. Exit
*/

#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Graph {
private:
    int numVertices;
    vector<list<int>> adjList;

public:
    Graph(int vertices) {
        numVertices = vertices;
        adjList.resize(vertices);
    }

    void insertEdge(int src, int dest) {
        if (src >= numVertices || dest >= numVertices || src < 0 || dest < 0) {
            cout << "Invalid edge!\n";
            return;
        }
        adjList[src].push_back(dest);
        adjList[dest].push_back(src); 
        cout << "Edge inserted.\n";
    }

    void deleteEdge(int src, int dest) {
        if (src >= numVertices || dest >= numVertices || src < 0 || dest < 0) {
            cout << "Invalid edge!\n";
            return;
        }
        adjList[src].remove(dest);
        adjList[dest].remove(src);
        cout << "Edge deleted.\n";
    }

    void searchEdge(int src, int dest) {
        if (src >= numVertices || dest >= numVertices || src < 0 || dest < 0) {
            cout << "Invalid vertices!\n";
            return;
        }
        for (int neighbor : adjList[src]) {
            if (neighbor == dest) {
                cout << "Edge exists between " << src << " and " << dest << ".\n";
                return;
            }
        }
        cout << "No edge exists between " << src << " and " << dest << ".\n";
    }

    void display() {
        cout << "Adjacency List:\n";
        for (int i = 0; i < numVertices; i++) {
            cout << i << ": ";
            for (int neighbor : adjList[i])
                cout << neighbor << " ";
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