#include<iostream>
using namespace std;
bool binarySearch2(int arr[],int s,int e,int key,int n){
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

}
