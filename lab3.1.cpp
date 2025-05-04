/*program to implement List ADT using an array of size 5*/
#include <iostream>
using namespace std;

#define MAX_SIZE 5

class ListADT {
private:
    int arr[MAX_SIZE];
    int size;

public:
    ListADT() : size(0) {}

    //Function to insert at end
    void insertEnd(int value) {
        if (size >= MAX_SIZE) {
            cout << "Error: List is full! Cannot insert." << endl;
            return;
        }
        arr[size++] = value;
    }

    //Function to insert at beginning
    void insertBeginning(int value) {
        if (size >= MAX_SIZE) {
            cout << "Error: List is full! Cannot insert." << endl;
            return;
        }
        for (int i = size; i > 0; i--) 
            arr[i] = arr[i - 1];
        arr[0] = value;
        size++;
    }

    //Function to insert at position
    void insertAtPosition(int value, int pos) {
        if (size >= MAX_SIZE) {
            cout << "Error: List is full! Cannot insert." << endl;
            return;
        }
        if (pos < 0 || pos > size) {
            cout << "Error: Invalid position!" << endl;
            return;
        }
        for (int i = size; i > pos; i--)
            arr[i] = arr[i - 1];
        arr[pos] = value;
        size++;
    }

    //Function to delete at end
    void deleteEnd() {
        if (size == 0) {
            cout << "Error: List is empty! Cannot delete." << endl;
            return;
        }
        size--;
    }

    //Function to delete at beginning
    void deleteBeginning() {
        if (size == 0) {
            cout << "Error: List is empty! Cannot delete." << endl;
            return;
        }
        for (int i = 0; i < size - 1; i++)
            arr[i] = arr[i + 1];
        size--;
    }

    //Function to delete at position
    void deleteAtPosition(int pos) {
        if (size == 0) {
            cout << "Error: List is empty! Cannot delete." << endl;
            return;
        }
        if (pos < 0 || pos >= size) {
            cout << "Error: Invalid position!" << endl;
            return;
        }
        for (int i = pos; i < size - 1; i++)
            arr[i] = arr[i + 1];
        size--;
    }

    //Function to search for a value
    void search(int value) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == value) {
                cout << "Element " << value << " found at index " << i << endl;
                return;
            }
        }
        cout << "Element " << value << " not found in the list." << endl;
    }

    //Function to display a value
    void display() const {
        if (size == 0) {
            cout << "List is empty!" << endl;
            return;
        }
        cout << "List: ";
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    //Reverse Function
    void reverse(int start, int end) {
        while (start < end) {
            swap(arr[start], arr[end]);
            start++;
            end--;
        }
    }

    //Rotate Function
    void rotate(int k) {
        if (size == 0) {
            cout << "Error: List is empty! Cannot rotate." << endl;
            return;
        }
        k = k % size;
        if (k == 0) return; 
        reverse(0, size - 1);
        reverse(0, k - 1);
        reverse(k, size - 1);
    }
};

// Function to display menu options
void displayMenu() {
    cout << "\nMenu:" << endl;
    cout << "1. Insert Beginning" << endl;
    cout << "2. Insert End" << endl;
    cout << "3. Insert at Position" << endl;
    cout << "4. Delete Beginning" << endl;
    cout << "5. Delete End" << endl;
    cout << "6. Delete at Position" << endl;
    cout << "7. Search" << endl;
    cout << "8. Display" << endl;
    cout << "9. Rotate" << endl;
    cout << "10. Exit" << endl;
    cout << "Enter choice: ";
}

int main() {
    ListADT list;
    int choice, value, k, pos;

    while (true) {
        displayMenu();
        
        if (!(cin >> choice)) {
            cout << "Error: Invalid input! Please enter a number." << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            list.insertBeginning(value);
            break;
        case 2:
            cout << "Enter value: ";
            cin >> value;
            list.insertEnd(value);
            break;
        case 3:
            cout << "Enter value and position: ";
            cin >> value >> pos;
            list.insertAtPosition(value, pos);
            break;
        case 4:
            list.deleteBeginning();
            break;
        case 5:
            list.deleteEnd();
            break;
        case 6:
            cout << "Enter position: ";
            cin >> pos;
            list.deleteAtPosition(pos);
            break;
        case 7:
            cout << "Enter value to search: ";
            cin >> value;
            list.search(value);
            break;
        case 8:
            list.display();
            break;
        case 9:
            cout << "Enter k (rotation count): ";
            cin >> k;
            list.rotate(k);
            list.display();
            break;
        case 10:
            cout << "Exiting program..." << endl;
            return 0;
        default:
            cout << "Error: Invalid choice! Please enter a number between 1 and 10." << endl;
        }
    }
}