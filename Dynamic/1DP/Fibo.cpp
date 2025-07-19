#include<iostream>
#include<vector>
using namespace std;
int recursion(int n){
    if(n==0)return 0;
    if(n==1)return 1;
    return (n-1)+(n-2);
}
int topdown(int n,vector<int>&dp){
    //recursion+memo
    //base case
    if(n==0)return 0;
    if(n==1)return 1;

    //bass yehi hi ek line extra h
    //memo
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n]=topdown(n-1,dp)+topdown(n-2,dp);
    return dp[n];
    
}
int bottomup(int n,vector<int>&dp){
    //base cases ko store kr lete h
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];
}
int spaceOpt(int n,int prev,int prevprev,int curr){
    if(n==0)return 0;
    if(n==1)return 1;
    int i=2; //as we handle two cases already
    while(i<=n){
        curr=prev+prevprev;
        prevprev=prev;
        prev=curr;
        i++;
    }
    return curr;
}

int getFibo(int n){
    // int prevprev=0;
    // int prev=1;
    // int curr=0;
    // return spaceOpt(n,prev,prevprev,curr);
    vector<int>dp(n+1,-1);
    // return topdown(n,dp);
    return bottomup(n,dp);


}
int main(){
    int n=3;
    cout<<getFibo(n)<<" ";
    return 0;

}