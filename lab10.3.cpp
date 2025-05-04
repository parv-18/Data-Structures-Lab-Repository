/*program to implement Priority Queue ADT using a Max Heap*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    // Function to maintain heap property after insertion
    void heapifyUp(int index) {
        while (index > 0 && heap[parent(index)] < heap[index]) {
            swap(heap[parent(index)], heap[index]);
            index = parent(index);
        }
    }

    // Function to maintain heap property after deletion
    void heapifyDown(int index) {
        int largest = index;
        int leftIdx = left(index);
        int rightIdx = right(index);

        if (leftIdx < heap.size() && heap[leftIdx] > heap[largest])
            largest = leftIdx;

        if (rightIdx < heap.size() && heap[rightIdx] > heap[largest])
            largest = rightIdx;

        if (largest != index) {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

    int parent(int i) { return (i - 1) / 2; }
    int left(int i)   { return 2 * i + 1; }
    int right(int i)  { return 2 * i + 2; }

public:

    //Inserts an element into the max heap
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
        cout << "Inserted " << value << " into the heap.\n";
    }

   // Deletes the maximum element from the max heap
    void deleteMax() {
        if (heap.empty()) {
            cout << "Heap is empty. Cannot delete.\n";
            return;
        }
        cout << "Deleted max element: " << heap[0] << endl;
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }
   
    //Displays elements of the max heap
      void display() {
        if (heap.empty()) {
            cout << "Heap is empty.\n";
            return;
        }
        cout << "Heap Elements: ";
        for (int val : heap)
            cout << val << " ";
        cout << endl;
    }

     //Searches for an element in the max heap
    void search(int value) {
        for (int i = 0; i < heap.size(); i++) {
            if (heap[i] == value) {
                cout << "Element " << value << " found at index " << i << endl;
                return;
            }
        }
        cout << "Element " << value << " not found in heap.\n";
    }

    // Performs heap sort and displays sorted elements 
    void heapSort() {
        vector<int> temp = heap;
        vector<int> sorted;

        while (!temp.empty()) {
            swap(temp[0], temp[temp.size() - 1]);
            sorted.push_back(temp.back());
            temp.pop_back();
            heapifyDownCustom(temp, 0);
        }

        cout << "Sorted elements (descending): ";
        for (int val : sorted)
            cout << val << " ";
        cout << endl;
    }

    void heapifyDownCustom(vector<int>& h, int index) {
        int largest = index;
        int l = 2 * index + 1;
        int r = 2 * index + 2;

        if (l < h.size() && h[l] > h[largest])
            largest = l;
        if (r < h.size() && h[r] > h[largest])
            largest = r;
        if (largest != index) {
            swap(h[index], h[largest]);
            heapifyDownCustom(h, largest);
        }
    }
};
int main() {
    MaxHeap pq;
    int choice, value;

    while (true) {
        cout << "\nPriority Queue using Max Heap:\n";
        cout << "1. Insert\n2. Delete\n3. Display\n4. Search\n5. Sort (Heap Sort)\n6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            pq.insert(value);
            break;
        case 2:
            pq.deleteMax();
            break;
        case 3:
            pq.display();
            break;
        case 4:
            cout << "Enter value to search: ";
            cin >> value;
            pq.search(value);
            break;
        case 5:
            pq.heapSort();
            break;
        case 6:
            cout << "Exiting program.\n";
            return 0;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    }
}
