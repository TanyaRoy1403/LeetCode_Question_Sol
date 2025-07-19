#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/*Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and using only constant extra space.*/

//bina array ko modify kiye binary search lgao

int findDuplicate(vector<int>&arr){
    int s=1;
    int e=arr.size()-1;
    int count=0;
    int duplicate=-1;

    while(s<=e){
        int mid=s+(e-s)/2;
        for(auto it:arr){
            if(it<=mid){count++;}
        }
        if(count>mid){duplicate=mid; e=mid-1;}
        else{s=mid+1;}
        
    }
    return duplicate;
    //tc: O(n), sc: O(1)
}
//tc: O(n) ,sc: O(n);
//using map

int findDuplicate(vector<int>& nums) {
    unordered_map<int,int>mp;
    for(auto & ch:nums){
            mp[ch]++;
    }
    for(auto& ch:mp){
        if(ch.second>1)
            return ch.first;
        }
    return -1;      
}
int main(){
    vector<int>arr={3,1,3,4,2};
    cout<<findDuplicate(arr);
}