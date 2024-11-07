#include<iostream>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

/*You are keeping the scores for a baseball game with strange rules. At the beginning of the game, you start with an empty record.

You are given a list of strings operations, where operations[i] is the ith operation you must apply to the record and is one of the following:

An integer x.
Record a new score of x.
'+'.
Record a new score that is the sum of the previous two scores.
'D'.
Record a new score that is the double of the previous score.
'C'.
Invalidate the previous score, removing it from the record.
Return the sum of all the scores on the record after applying all the operations.*/


int solve(vector<string>&s){
    stack<int>st;
    int sum=0;
    for(auto&ch:s){
        if(ch=="C"){
            if(!st.empty()){
                sum -=st.top();
                st.pop();
            }else if(ch=="D"){
                sum+=2*st.top();
                st.push(sum);
            }else if(ch=="+"){
                int first=st.top();
                st.pop();
                int sec=st.top();
                st.push(first);
                int sum_val=first+sec;
                sum+=sum_val;
                st.push(sum_val);
            }else{
                int num=stoi(ch);
                sum+=num;
                st.push(num);
            }
        }
    }
    return sum;
}
int main(){
    vector<string>arr={"5","2","C","D","+"};
    cout<<solve(arr);
}