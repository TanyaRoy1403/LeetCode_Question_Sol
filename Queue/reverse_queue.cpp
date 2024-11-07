#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
using namespace std;

//using satck
void rev_queue(queue<int>&q){
    stack<int>st;
    //queue se nikalo or satck me daalo
    while(!q.empty()){
        int top=q.front();
        q.pop();
        st.push(top);
    }
    while(!st.empty()){
        int top_stack=st.top();
        st.pop();
        q.push(top_stack);
    }
}
void rev_queueRec(queue<int>&q){
    if(q.empty()){
        return ;
    }
    
    int top_ele=q.front();
    q.pop();
    //ab iss ko continue kro
    rev_queueRec(q);
    //fir originality maintain rkhne ke backtracking kro
    q.push(top_ele);
}
int main(){
    queue<int>q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    // rev_queue(q);
    rev_queueRec(q);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}