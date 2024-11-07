#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*The distance of a pair of integers a and b is defined as the absolute difference between a and b.

Given an integer array nums and an integer k, return the kth smallest distance among all the pairs nums[i] and nums[j] where 0 <= i < j < nums.length.*/

/*---------------------------------------------Brute force-------------------------------------------------------------------------------*/

//TLE
int solve_brute(vector<int>&arr,int k){
    vector<int>ans;
    int n=arr.size();
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int diff=abs(arr[i]-arr[j]);
        ans.push_back(diff);
        }
    }
    sort(begin(ans),end(ans));
    
  
    return ans[k-1];
}
/*-------------------------------------------using count array----------------------------------------------------*/
int slove_count_arr(vector<int>&arr,int k){
    int n=arr.size();
    int max_ele=*max_element(begin(arr),end(arr));
    vector<int>count_arr(max_ele+1,0);  //precomput kr liye h ki kitna kitna diff ho skta h
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int diff=abs(arr[i]-arr[j]);
            count_arr[diff]++;  //fre add kr diye h ki yeh diff kitni baar aaya h
        }
    }
    for (int d = 0; d <=max_ele; d++) {
            k -= count_arr[d];
        if (k <= 0) {
            return d; //returning kth smallest distance
        }
    }
    return -1;
/*Time complexity:O(n^2)---
---space complexity:O(max_ele)-----------------------------------------------------*/
}
int main(){
    vector<int>arr={1,6,1};
    int k=3;
    cout<<solve_brute(arr,k);
    cout<<endl;
    cout<<slove_count_arr(arr,k);
}