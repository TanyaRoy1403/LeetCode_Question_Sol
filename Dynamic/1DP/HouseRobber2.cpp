#include<iostream>
#include<vector>
using namespace std;
vector<int>dp;
int solve(vector<int>house ,int i,int n){
    if(i>n)return 0;
    if(dp[i]!=-1)return dp[i];
    int steal=house[i]+solve(house,i+2,n);
    int skip=solve(house,i+1,n);
    dp[i]=max(steal,skip);
    return dp[i];

}
int rob(vector<int>house){
    int n=house.size();
    dp.resize(n,-1);
    if(n==1)return house[1];
    if(n==2)return max(house[0],house[1]);

    //case 1: when 0th house  rob then last house must not rob
    int take_0th_house=solve(house,0,n-2);
    int take_0th_not=solve(house,1,n-1);
    return max(take_0th_house,take_0th_not);

}
int main(){
    vector<int>house={1,2,3,1};
    cout<<rob(house);
}