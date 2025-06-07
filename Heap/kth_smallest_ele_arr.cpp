#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int solve(vector<int>&arr,int k){
    priority_queue<int>mp;
    for(int i=0;i<k;i++){
        mp.push(arr[i]);
    }
    for(int i=k;i<arr.size();i++){
        int ele=arr[i];
        if(mp.top()>ele){
            mp.pop();
            mp.push(ele);
        }
    }
    return mp.top();
}
int main(){
    vector<int>arr={2, 3, 1, 20, 15};
    cout<<solve(arr,4);
    return 0;
}
