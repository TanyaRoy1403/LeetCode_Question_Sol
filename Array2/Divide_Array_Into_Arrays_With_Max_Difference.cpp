// #include<iostream>
// #include<vector>
// #include<algorithm>
#include<bits/stdc++.h>
using namespace std;
/*You are given an integer array nums of size n where n is a multiple of 3 and a positive integer k.
Divide the array nums into n / 3 arrays of size 3 satisfying the following condition:
The difference between any two elements in one array is less than or equal to k.
Return a 2D array containing the arrays. If it is impossible to satisfy the conditions, return an empty array. And if there are multiple answers, return any of them.*/
vector<vector<int>> solve(vector<int>&arr,int k){
    int n=arr.size();
    sort(begin(arr),end(arr));
    vector<vector<int>>ans;
    for(int i=0;i<n;i+=3){
        if(arr[i+2]-arr[i]>k){
            return {};
        }
        ans.push_back({arr[i],arr[i+1],arr[i+2]});
    }
    return ans;

}
int main(){
    vector<int>arr={1,3,4,8,7,9,3,5,1};
    int k=2;
    vector<vector<int>>ans=solve(arr,k);
    for(auto  &it:ans){
        for(auto &x:it){
            cout<<x<<" ";
        }
    }
}