#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int solve(vector<int>&arr,int k){
    priority_queue<int,vector<int>,greater<int>>hp;
    for(auto&ch:arr){
        hp.push(ch);
    }
    int ans=1;
    while(!hp.empty()&& k>0){
        ans=ans*hp.top();
        hp.pop();
        k--;
    }
    return ans; 
 

}
int miniProduct(vector<int>&arr,int k){
    int n=arr.size();
    return solve(arr,k);
}
int  main(){
    vector<int>arr={11, 8, 5, 7, 5, 100};
    cout<<miniProduct(arr,4);
} 