#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
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