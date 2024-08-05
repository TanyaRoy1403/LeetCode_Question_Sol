#include<iostream>
#include<string>
#include<stack>
#include<string>
using namespace std;
/*A valid parentheses string is either empty "", "(" + A + ")", or A + B, where A and B are valid parentheses strings, 
and + represents string concatenation.

For example, "", "()", "(())()", and "(()(()))" are all valid parentheses strings.
A valid parentheses string s is primitive if it is nonempty, and there does not exist a way to split it into s = A + B, 
with A and B nonempty valid parentheses strings.

Given a valid parentheses string s, consider its primitive decomposition: s = P1 + P2 + ... + Pk, 
where Pi are primitive valid parentheses strings.

Return s after removing the outermost parentheses of every primitive string in the primitive decomposition of s.Input: s = "(()())(())"
Output: "()()()"*/


string decom(string s){
/*---//*-----------------------------------------------wihout using stack-------------------------------------------------------------------*/
    int counter=0;
    string result="";
    for(auto &ch:s){
        if(ch==')'){
            counter--;
        }
        if(counter!=0){
            result+=ch;
        }
        if(ch=='('){
            counter++;
        }
    }
    return result;
/*---//*Time complexity:o(N)
------//*Space complexity:O(1)----------------------------------------------------------------------------------------------------*/

/*--//^--------------------------------------using stack-----------------------------------------------------------------------*/
        stack<char> st;
        string ans;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(') 
            {
                if(!st.empty()) ans.push_back(s[i]);
                st.push(s[i]);
            }
            else
            {
                st.pop();
                if(!st.empty()) ans.push_back(s[i]);
            }
        }
        return ans;
}
/*--//^timecomplexity:O(n)
----//^space complexity:O(n)--------------------------------------------------------------------------------------------------*/
int main(){
    string s="(()())(())";
    cout<<decom(s)<<" ";
}