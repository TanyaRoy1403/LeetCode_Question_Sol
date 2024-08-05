#include<iostream>
using namespace std;
int binarySearch(int arr[], int left, int right, int key, int i) {
    if (left > right) {
        return -1; // Element not found
    }

    int mid = left + (right - left) / 2;

    if (arr[mid] == key) {
        return mid; // Element found
    } else if (arr[mid] < key) {
        return binarySearch(arr, mid + 1, right, key, i + 1); // Search in the right half with incremented i
    } else {
        return binarySearch(arr, left, mid - 1, key, i + 1); // Search in the left half with incremented i
    }
}
bool binarySearch2(int arr[],int s,int e,int key){
    ///base case
    if(s>e){

        return false;
    }
    int mid=s+(e-s)/2;
    if(arr[mid]==key){
        return true;
    }
    else if(arr[mid]>key){
            return binarySearch2(arr,s,mid-1,key);

    }
    else{
        return binarySearch2(arr,mid+1,e,key);
    }
}

int main(){
    int arr[5]={1,2,3,4,5};
    int s=0;
    int e=4;
    int key=2;
//    int i=0;
//    int result=binarySearch(arr,s,e,key,i);
//    if(result !=-1){
//        cout<<"Element found at index:"<<result<<endl;
//    }
//    else{
//        cout<<"Element not found"<<endl;
//    }
  bool result=binarySearch2(arr,s,e,key);
  if(result){
    cout<<"Found"<<endl;
  }
  else {
    cout<<"not found"<<endl;
  }
}

