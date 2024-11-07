#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/**/

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