#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
/*Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.*/


vector<int> solve(vector<int>&arr,int target){
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            if(arr[i]+arr[j]==target){
                return {i,j}; 
            }
        }
    }
    return {-1,-1};

}

//optiimal solution
vector<int>op_solve(vector<int>&arr,int target){
    unordered_map<int,int>mp;
    for(int i=0;i<arr.size();i++){
        int etr=target-arr[i];
        if(mp.count(etr)){
            return {mp[etr],i};
        }else{
            mp[arr[i]]=i;
        }
    }
    return {};
}
int main(){
    vector<int>arr={2,7,11,15};
    vector<int>ans=op_solve(arr,9);
    for(auto it:ans){
        cout<<it;
    }

}