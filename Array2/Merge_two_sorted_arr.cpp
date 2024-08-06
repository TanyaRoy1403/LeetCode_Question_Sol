#include<iostream>
#include<vector>
using namespace std;

/*You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, 
representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. 
To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and 
the last n elements are set to 0 and should be ignored. nums2 has a length of n.*/


vector<int> merge_arr(vector<int>&arr1,vector<int>&arr2,vector<int>&result){
    int n=arr1.size();
    int m=arr2.size();
    int i=0;
    int j=0;
    int k=0;
    while(i<n&&j<m){
        if(arr1[i]<arr2[j]){
            result.push_back(arr1[i]);
            i++;
        }else{
            result.push_back(arr2[j]);
            j++;
        }
    }
    while(i<n){
        result.push_back(arr1[i]);
        i++;
    }
    while(j<m){
        result.push_back(arr2[j]);
        j++;
    }
}
int main(){
    vector<int>arr1={20,40,60,80,90,100};
    vector<int>arr2={10,30,50,70};
    vector<int>result;
    merge_arr(arr1,arr2,result);
    for(auto &it:result){
        cout<<it<<" ";
    }
}