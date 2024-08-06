#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

/*Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that 
they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.

The tests are generated such that there is exactly one solution. You may not use the same element twice.

Your solution must use only constant extra space.*/


vector<int> solve(vector<int>&arr,int target){
    int s=0;
    int e=arr.size()-1;
    while(s<=e){
        int sum=arr[s]+arr[e];
        if(sum==target){
            return {s+1,e+1};
        }else if(target>sum){
            s++;
        }else{
            e--;
        }
    }
    return {};
}

int main(){
    vector<int>arr={2,3,4};
    vector<int>ans=solve(arr,6);
    for(auto it:ans){
        cout<<it;
    }


}