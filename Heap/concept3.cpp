#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

void heapify(int arr[],int n,int idxlarge){
    int largest=idxlarge;
    int leftchild=2*idxlarge+1;
    int rightchild=2*idxlarge+2;
    if(leftchild<n&&arr[idxlarge]<arr[leftchild]){
        largest=leftchild;
    }
    if(rightchild<n&&arr[idxlarge]<arr[rightchild]){
        largest=rightchild;
    }
    if(largest!=idxlarge){
        swap(arr[idxlarge],arr[largest]);
        heapify(arr,n,largest);
    }
}
void printHeap(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {10, 5, 20, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Build max-heap (start heapifying from last non-leaf node)
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    cout << "Array after heapify (Max Heap): ";
    printHeap(arr, n);

    return 0;
}