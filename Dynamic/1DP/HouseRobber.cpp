#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int recursion(vector<int>&house,int i){
    int n=house.size();
    if(i>=n)return 0; //we can not skip first hiuse islye i=0 se start hoga
    int steal=house[i]+recursion(house,i+2);
    int skip =recursion(house,i+1);
    return max(steal,skip);

}
int topdown(vector<int>&house, int i, vector<int>&dp){
    //base case
    if(i>=house.size())return 0;
    if(dp[i]!=-1){
        return dp[i];
    }
    int skip=topdown(house,i+1,dp);
    int take=house[i]+topdown(house,i+2,dp);
    dp[i]=max(skip,take);
    return dp[i];

}
int bottomup(vector<int>&house,vector<int>&dp){
    //base case
    int n=house.size();
    if(n==1) return house[0];

    dp[0]=0; //ek v house na ho
    dp[1]=house[0]; //sirf ek hi house ho  , house[i-1] index pe hoga uska value
    for(int i=2;i<=n;i++){
        int steal=house[i-1]+ dp[i-2]; //house[i-1]value of current house jisko chura rhe h, house[i-2] value pichle ghr tk ka chura chuke h adj chor ke
        int skip=dp[i-1]; //agr current index wale ghr ko nhi churate h to uske phele churaye hue value h yeh 
        dp[i]=max(steal,skip);

    }
    return dp[n];

}
int spaceOpt(vector<int>house){
    int n=house.size();
        if(n==0)return 0;
        if(n==1)return house[0];
        int prev2=house[0];
        int prev1=max(house[0],house[1]);
        for(int i=2;i<n;i++){
            int curr=max(prev1,prev2+house[i]);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
}

int rob(vector<int>house){
    int n=house.size();
    vector<int>dp(n+1);
    // int i=0;
    // return topdown(house,i,dp);
    return bottomup(house, dp);

}
int main(){
    vector<int>house={1,2,3,1};
    cout<<rob(house);
    cout<<endl;
    cout<<"using recursion:";
    cout<<recursion(house,0); 
    cout<<endl;
    cout<<"using spaceOpt:";
    cout<<spaceOpt(house);
}