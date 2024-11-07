#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MOD=1e9+7;

//1498
/*You are given an array of integers nums and an integer target.

Return the number of non-empty subsequences of nums such that the sum of the minimum and maximum element on it is less or equal to target. 
Since the answer may be too large, return it modulo 109 + 7.*/

/*//&---------------Brute force-->binary search------------------------------------------------------------------*/

int solve(vector<int>&nums,int target){
    int n=nums.size();
    sort(begin(nums),end(nums));
    //precompute the pow(2,e-s);
    vector<int>power(n); //to store power of 2 ka index of nums
    power[0]=1;
    for(int i=1;i<n;i++){
        power[i]=(power[i-1]*2)%MOD;
    }    
    //binary search 
    int result=0;
    int s=0;
    int e=n-1;
    while(s<=e){
        int diff=e-s;
        if(nums[s]+nums[e]<=target){
            result =(result+ power[diff])%MOD;
            s++;
        }else{
            e--;
        }
    }
    return result;
}
/*Time complexity:O(nlogn)---
---space coomplexity:O(n)--------------*/

/* we can also solve using slinding window (variable size)*/

int solve2(vector<int>&nums,int target){
    int n=nums.size();
    sort(begin(nums),end(nums));
    //precompute the pow(2,e-s);
    vector<int>power(n); //to store power of 2 ka index of nums
    power[0]=1;
    for(int i=1;i<n;i++){
        power[i]=(power[i-1]*2)%MOD;
    } 

    //pointer to deniate size of window
    int s=0,e=0;
    int result=0;
    while(e<n){
        //expand the wiindow
        while(e<n&&nums[s]+nums[e]<=target){
            e++;
        }
        if(e>s){
            result= (result+power[e-s-1])%MOD;
        }
        //shrink the window
        s++;
    }
    return result;
}

int main(){
    vector<int>arr={2,3,3,4,6,7};
    int target=12;
    cout<<solve2(arr,target);
}