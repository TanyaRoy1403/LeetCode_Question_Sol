#include<iostream>
#include<vector>
using namespace std;



void solve(int n,int open,int close,string s,vector<string>& ans){
    if(s.size()==2*n){
        ans.push_back(s);
        return;
    }
    if(open<n){
        solve(n,open+1,close,s+'(',ans);
        s.pop_back();
    }
    if(close<open){
        solve(n,open,close+1,s+')',ans);
        s.pop_back();
    }
}
vector<string> generateParenthesis(int n) {
    vector<string> ans;
    string s;
    int open=0,close=0;
    solve(n,open,close,s,ans);
    return ans;
}
int main(){
    int n=3;
    vector<string> ans=generateParenthesis(n);
    for(auto x:ans){
        cout<<x<<endl;
    }
    return 0;
}