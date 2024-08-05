// #include<iostream>
// #include<vector>
// #include<algorithm>
#include<bits/stdc++.h>
using namespace std;

/*You are given two integer arrays of equal length target and arr. In one step, you can select any non-empty 
subarray of arr and reverse it. You are allowed to make any number of steps.

Return true if you can make arr equal to target or false otherwise.*/

bool make_equal(vector<int>&target,vector<int>&arr){
    //brute force--sorting
    int n=target.size();
    int m=arr.size();
    sort(begin(arr),end(arr));
    sort(begin(target),end(target));
    if(n!=m){
        return false;
    }
    for(int i=0;i<m;i++){
        if(arr[i]!=target[i]){
            return false;
        }
    }
    return true;
}

bool make_equl2(vector<int>&target,vector<int>&arr){
    //better solution-->using dictionary
    int n=target.size();
    int m=arr.size();
    unordered_map<int,int>arr_fre;
    unordered_map<int,int>tar_fre;
    if(n!=m){
        return false;
    }
    for(auto &it:arr){
        arr_fre[it]++;
    }
    for(auto &it:target){
        tar_fre[it]++;
    }
    for(auto &it:arr_fre){
        if(tar_fre[it.first]!=it.second){
            return false;
        }
    }
    return true;

}