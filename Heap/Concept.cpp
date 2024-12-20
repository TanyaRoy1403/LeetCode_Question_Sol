#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Heap {
public: 
    int* arr;       // Array to store heap elements
    int capacity;   // Max capacity of heap
    int index;      // Current size of the heap

    Heap(int n) {
        this->capacity = n;
        arr = new int[n + 1];  // Extra space for 1-based indexing
        index = 0;
    }

    // Print heap elements
    // void printHeap() {
    //     for (int i = 1; i <= index; i++) {
    //         cout << arr[i] << " ";
    //     }
    //     cout << endl;
    // }

    // Insert a new value into the heap
    void insert(int val) {
        if (index == capacity) {
            cout << "Overflow" << endl;
            return;
        }

        // Insert at end, then bubble up
        index++;
        arr[index] = val;
        cout << "Inserting " << val << " at index: " << index << endl;

        int i = index;
        while (i > 1) {
            int parentIndex = i / 2;

            // Swap if parent is less than the current node
            if (arr[parentIndex] < arr[i]) {
                swap(arr[parentIndex], arr[i]);
                i = parentIndex;
            } else {
                break;
            }
        }
    }
    

    // Delete the root element from the heap
    void deleteFromHeap() {
        if (index == 0) {
            cout << "Heap is empty, cannot delete" << endl;
            return;
        }

        // Replace root with last element and decrease size
        arr[1] = arr[index];
        index--;

        // Heapify down from the root to maintain heap property
        ::heapify(arr, index, 1);
    }
};

void heapify(int* arr, int n, int i) {
    int largest = i;
    int leftChild = 2 * i;
    int rightChild = 2 * i + 1;

    if (leftChild <= n && arr[leftChild] > arr[largest]) {
        largest = leftChild;
    }
    if (rightChild <= n && arr[rightChild] > arr[largest]) {
        largest = rightChild;
    }
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}



// Build a heap from a given array
void buildHeap(int * arr,int n) {
    for (int i = n / 2; i >= 1; i--) {
        heapify(arr, n, i);
    }
}

// Print vector heap elements
void printHeap(int *arr,int n) {
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    Heap heapObj(10);
	int arr[]={0,10,15,20,30,40};
	buildHeap(arr,5);
	printHeap(arr,5);


	
    

}
