#include<iostream>
#include<vector>
using namespace std;

class Heap{
    public:
    int *arr;
    int capacity;
    int index;
    Heap(int n){
        this->capacity=n;
        arr=new int[n+1];
        index=0;
    }
    void insert(int value);
    void delettion();
    void printHeap();

};
void heapify(int *arr,int n,int i){
    int largest=i;
    int leftchild=2*i;
    int rightchild=2*i+1;
    if(leftchild<=n&&arr[largest]<arr[leftchild]){
        largest=leftchild;
    }
    if(rightchild<=n&&arr[rightchild]<arr[largest]){
        largest=rightchild;
    }
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }

}  
void Heap::insert(int value){
     if (index == capacity) {
        cout << "Heap Overflow!" << endl;
        return;
    }

    // Insert at end, then bubble up
    index++;
    arr[index] = value;
    cout << "Inserting " << value << " at index: " << index << endl;

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
void Heap::printHeap() {
    for (int i = 1; i <= index; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void buildHeap(int* arr, int n) {
    for (int i = n / 2; i >= 1; i--) {
        heapify(arr, n, i);
    }
}
void printHeap(int* arr, int n) {
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main(){
      Heap heapObj(10);

    heapObj.insert(50);
    heapObj.insert(30);
    heapObj.insert(40);
    heapObj.insert(10);
    heapObj.insert(20);
    heapObj.insert(5);
    cout << "Heap after insertions: ";
    heapObj.printHeap();
    cout<<endl;
       int arr[] = {0, 10, 15, 20, 30, 40};  // 1-based index array
    buildHeap(arr, 5);
    cout << "Heap after building from array: ";
    printHeap(arr, 5);

return 0;


} 