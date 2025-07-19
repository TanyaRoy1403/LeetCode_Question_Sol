#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int>&cost,int i){ //using recursion
    int n=cost.size();
    if(i>=n)return 0; //base case
    int one_step_cost=solve(cost,i+1);
    int two_step_cost=solve(cost,i+2);
    int ans=cost[i]+min(one_step_cost,two_step_cost);
    return ans;
}
int topDown(vector<int>cost,int i){
    int n=cost.size();
    vector<int>dp(n+1,-1);
    //base case
    if(i>=n)return 0;
    if(dp[i]!=-1)return dp[i];
    int one_step=cost[i]+topDown(cost,i+1);
    int two_step=cost[i]+topDown(cost,i+2);
    dp[i]=min(one_step,two_step); 
    return dp[i];
}
int bottomup(vector<int>&cost){
    int n=cost.size();
    vector<int>dp(n+1,0);
    dp[0]=cost[0];
    dp[1]=cost[1];
    for(int i=2;i<n;i++){
        dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
    }
    return min(dp[n-1],dp[n-2]);
    
}
int spaceOpt(vector<int>&cost){
    int n=cost.size();
    int prev2=cost[1];
    int prev1=cost[0];
    for(int i=2;i<n;i++){
        int curr=cost[i]+min(prev1,prev2);
        prev1=prev2;
        prev2=curr;
    }
    return min(prev1,prev2);
}
int getCost(vector<int>cost){
    //after you draw recursiove tree you will absorb for every solve fun value is solve(cost_i,i)-->cost[i]+min(one_step_cost,two_step_cost)
    // return min(solve(cost,0),solve(cost,1)); //recursion
    return min(topDown(cost,0),topDown(cost,1));
    
}
int main(){
    vector<int>cost={10,15,20};
    cout<<getCost(cost);
    cout<<endl;
    cout<<"bottom up:"<<" ";
    cout<<bottomup(cost);
    cout<<endl;
    cout<<"Space opt :"<<" ";
    cout<<spaceOpt(cost);

}