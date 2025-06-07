#include<iostream>
#include<vector>
using namespace std;
int pivotInx(vector<int>&arr){
    int n=arr.size();
    int s=0;
    int e=n-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        if(mid+1<n &&arr[mid]>arr[mid+1]){
            return mid;
        }if(mid>=0&&arr[mid]<arr[mid-1]){
            return mid-1;
        }if(arr[mid]<arr[s]){
            e=mid-1;
        }else{
            s=mid+1;
        }
    }
    return -1;
}
int binarySearch(int s,int e,int target,vector<int>&arr){
    while(s<=e){
        int mid=s+(e-s)/2;
        if(arr[mid]==target){
            return mid;
        }if(target>arr[mid]){
            s=mid+1;
        }else{
            e=mid-1;
        }
    }
    return -1; 
}
int search(vector<int>&nums,int target){
    int pivotIndex=pivotInx(nums);
    int n=nums.size();
    //line A start->0 end->pivotIndex
    if(target>=nums[0]&& target<=nums[pivotIndex]){
        return binarySearch(0,pivotIndex,target,nums);
    }else{
    //line B start->pivotIndex+1 end->n-1
        return binarySearch(pivotIndex+1,n-1,target,nums);
    }
    return -1;
}
int main(){
    vector<int>arr={4,5,6,7,0,1,2};
    int n=arr.size();
    int target=0;

    cout<<search(arr,target);
}