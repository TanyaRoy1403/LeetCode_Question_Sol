#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int bottomUP(string word1,string word2,vector<vector<int>>&dp,int m,int n){
    //base case
    dp[0][0]=0;
    for(int i=0;i<=m;i++){ //
        dp[i][0]=i;// word2 pura empty h isliye word1 ko v pura delete krna prega uske char ko
    }
    for(int j=0;j<=n;j++){
        dp[0][j]=j; //word1 pura empty h
    }

    //now 
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];  // characters match
            else
                dp[i][j] = 1 + min({dp[i-1][j],    // delete
                                    dp[i][j-1],    // insert
                                    dp[i-1][j-1]}); // replace
            }
        }
        return dp[m][n];
    
}
int minDist(string word1, string word2){
    int m=word1.length();
    int n=word2.length();
    int s=m*n;
    vector<vector<int>>dp(m+1,vector<int>(n+1,0));
    return bottomUP(word1,word2,dp,m ,n);
}
int main(){
    string word1= "horse";
    string word2="ros";
    cout<<minDist(word1,word2);
    return 0;
}