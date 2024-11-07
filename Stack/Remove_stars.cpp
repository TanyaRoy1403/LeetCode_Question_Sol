#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;

string solve(string s){
    stack<char>st;
    string result="";
    for(auto &ch:s){
        if(ch=='*'){
            st.pop();
        }else{
            st.push(ch);
        }
    }
    while(!st.empty()){
        result.push_back(st.top());
        st.pop();
    }
    reverse(begin(result),end(result));
    return result;
}
int main(){
    string s="leet**cod*e";
    cout<<solve(s)<<" ";
    return 0;
}