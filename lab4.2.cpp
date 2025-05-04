/*program to implement List ADT using a singly linked list using insert ascending, merge, display operations+*/
#include <iostream>

using namespace std;

class List {
private:
    struct Node {
        int data;
        Node* next;
    };

    Node* head;

    // Private member function to get the head of the list
    Node* getHead() {
        return head;
    }

public:
    List(); // Constructor
    void insertAscending(int num);
    void merge(List& other);
    void display();
};

// Constructor Definition
List::List() {
    head = nullptr; // Initializes head as null
}

// Function to insert nodes in ascending order
void List::insertAscending(int num) {
    Node* newNode = new Node;
    newNode->data = num;
    newNode->next = nullptr;

    // Inserting as the first element
    if (head == nullptr || head->data >= newNode->data) {
        newNode->next = head;
        head = newNode;
    } else {
        // Inserting in the correct position
        Node* current = head;
        while (current->next != nullptr && current->next->data < newNode->data) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Function to merge two lists
void List::merge(List& other) {
    Node* currentOther = other.getHead(); // Accessing the head of the other list
    while (currentOther != nullptr) {
        insertAscending(currentOther->data); // Insert each element in ascending order
        currentOther = currentOther->next;
    }
}

// Function to display the list
void List::display() {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

int main() {
    List list1;
    List list2;
    int choice, num;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert Ascending\n";
        cout << "2. Merge with Another List\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to insert: ";
                cin >> num;
                list1.insertAscending(num);
                break;
            case 2:
                cout << "Merging with another list. " << endl;
                do {
                    cout << "Enter a value for the second list (0 to stop): ";
                    cin >> num;
                    if (num != 0) {
                        list2.insertAscending(num);
                    }
                } while (num != 0);
                list1.merge(list2);
                break;
            case 3:
                cout << "Displaying list: ";
                list1.display();
                break;
            case 4:
                cout << "Exiting the program...\n";
                break;
            default:
                cout << "Invalid Choice!!!\n";
                break;
        }
    } while (choice != 4);

    return 0;
}
