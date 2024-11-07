#include<iostream>
#include<vector>
#include<stack>
using namespace std;

/*Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.*/

/*-----------------------------------------------Brute force-------------------------------------------*/

bool solve(string s){
    int count_open1=0;
    int count_clos1=0;
    int count_open2=0;
    int count_clos2=0;
    int count_open3=0;
    int count_clos3=0;

    for(auto &ch:s){
        if(ch=='('){
            count_open1++;
        }
        else if(ch==')'){
            count_clos1++;
        }
        else if(ch=='{'){
            count_open2++;
        }
        else if(ch=='}'){
            count_clos2++;
        }
        else if(ch=='['){
            count_open3++;
        }
        else{
            count_clos3++;
        }
    }
    if(count_open1==count_clos1&&count_open2==count_clos2&&count_open3==count_clos3){
        return true;
    }
    return true;
}

bool solve2(string s){
    stack<char>st;
    for(auto &ch:s){
        if(s.empty()||ch=='('||ch=='{'||ch=='['){
            st.push(ch);
            continue;
        }
        if(ch==')'){
            if(st.top()=='('){
                st.pop();
            }else{
                return false;
            }
        }
        else if(ch=='}'){
            if(st.top()=='{'){
                st.pop();
            }
            else{
                return false;
            }
        }
        else if(ch==']'){
            if(st.top()=='['){
                st.pop();
            }else{
                return false;
            }
        }
    }
return true;

}
int main(){
    string s="([])";
    bool result=solve2(s);
    if(result){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }
}