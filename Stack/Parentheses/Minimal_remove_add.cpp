#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/*A parentheses string is valid if and only if:

It is the empty string,
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
You are given a parentheses string s. In one move, you can insert a parenthesis at any position of the string.

For example, if s = "()))", you can insert an opening parenthesis to be "(()))" or a closing parenthesis to be "())))".
Return the minimum number of moves required to make s valid.*/

int minAddToMakeValid(string s) {
    int count=0;
    stack<char>st;
    for(auto &ch:s){
        if(ch=='('){
            count++;
            st.push(ch);
        }else{
            if(!st.empty()){
                //match mil gya hoga to count ko km v to krna hog
                st.pop();//top wala hi to match hus hoga
                count--;
            }else{
                //macth nhi milq
                count++;
            }
        }
    }
    return count;
}
int main(){
    string s="(()))";
    string s1="(((";
    cout<<minAddToMakeValid(s1);
}