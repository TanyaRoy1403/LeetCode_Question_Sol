#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
//t.c-->O(n)
int solve(vector<int>&arr){
    unordered_map<int,int>mp;
    for(auto &it:arr){
        mp[it]++;
    }
    for(auto &x:mp){
        if(x.second%2!=0){
            return x.first;
        }
    }
    return -1;
}


int main(){
    vector<int>arr={1, 1, 2, 2, 1, 1, 2, 2, 13, 1, 1, 40, 40, 13, 13};
    cout<<solve(arr);
}