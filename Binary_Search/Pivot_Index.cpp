#include<iostream>
#include<vector>
using namespace std;
int pivotInx(vector<int>&arr){
    int n=arr.size();
    int s=0;
    int e=n-1;
    // while(s<=e){
    //     int mid=s+(e-s)/2;
    //     if(mid+1<n &&arr[mid]>arr[mid+1]){
    //         return mid;
    //     }if(mid>=0&&arr[mid]<arr[mid-1]){
    //         return mid-1;
    //     }if(arr[mid]<arr[s]){
    //         e=mid-1;
    //     }else{
    //         s=mid+1;
    //     }
    // }
    // return -1;
    while(s<e){
        int mid=s+(e-s)/2;
        if(arr[mid]>=arr[0]){
            s=mid+1;
        }else{
            e=mid;
        }
    }
    return s;
}
int main(){
    vector<int>arr={50,60,70,80,10,20,30,40};
    int n=arr.size();
    int result=pivotInx(arr);
    cout<<result;
}