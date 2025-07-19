#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//we are going to solve using DP and Binary search /linear search

//top down : rec+memo
//intervals wale question me hm phele is sortiing hi try krte h

int n;

int solve(vector<vector<int>>events,int idx ,int k,vector<vector<int>>&dp){
    //base case
    if(idx>=n ||k==0)return 0;

    //memo
    if(dp[idx][k]!=-1)return dp[idx][k];
    int start=events[idx][0];
    int end=events[idx][1];
    int value=events[idx][2];

    int skip=solve(events,idx+1,k,dp);
    //to take lets find interval whose starting date is not matches with ending day of previously taken interval
    //liner search

    int j=idx+1;
    for(;j<n;j++){
        if(events[j][0]>events[idx][1]){
            break;
        }
    }
    int take=value+solve(events,j,k-1,dp);
    dp[idx][k]=max(skip,take); //store

    return dp[idx][k];
}

int maxEvent(vector<vector<int>>events,int k){
    //sort event by its starting days
    sort(begin(events),end(events));
    n=events.size();
    vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
    return solve(events,0,k,dp);
    
}
int main(){
    vector<vector<int>>events={{1,2,4},{3,4,3},{2,3,1}};
    int k=2;
    cout<<maxEvent(events,k);

}