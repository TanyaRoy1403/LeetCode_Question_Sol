#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<algorithm>
using namespace std;

/*You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent 
and equal letters and removing them.

We repeatedly make duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.*/

/*---------------------------------------Brute force---------------------------------------*/

string solve(string s){
    string ans="";
    for(auto&ch:s){
        if(ans.empty()){
            ans.push_back(ch);
        }else if(ch==ans.back()){
            ans.pop_back();
        }else if(ch!=ans.back()){
            ans.push_back(ch);
        }
    }
return ans;
}
/* -----------------optimal solution-------------------------------------*/
string remove_adj(string s){
    stack<char>st;
    string ans="";
    for(auto&ch:s){
        if(st.empty()||st.top()!=ch){
            st.push(ch);
        }else{
            st.pop();
        }
    }
    //final traversal  to print ans
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main(){
    string s="abbaca";
    cout<<solve(s);
    cout<<endl;
    cout<<remove_adj(s);
}