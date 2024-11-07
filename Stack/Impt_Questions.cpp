#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//iterative approach
void deleteMiddleEle(stack<int>&st){
    stack<int>st2;
    int n=st.size();
    int track_size=0;
    while(track_size<n/2){
        int top_store=st.top();
        st2.push(top_store);
        st.pop();
        track_size++;
    }
    //middle ko pop kro
    st.pop();
    //wapas se st2 me pre ele ko st daal do
    while(!st2.empty()){
        int top=st2.top();
        st.push(top);
        st2.pop();
    }
}
//using recursion and backtrackin
void deleMiddle(stack<int>&st, int size,int count){
   
    //base case
    if(count==size/2){
        st.pop();
        return;
    }
    int store_top=st.top();
    st.pop();
    deleMiddle(st,size,count+1);
    //backtrack to maitain the originality
    st.push(store_top);
}
void insertBottom(stack<int>&st1,int ele){
    stack<int>st2;
    if(st1.empty()){
        return;
    }
    while(!st1.empty()){
        int top=st1.top();
        st2.push(top);
        st1.pop();
    }
    //insert the ele
    st1.push(ele);
    while(!st2.empty()){
        int top=st2.top();
        st1.push(top);
        st2.pop();
    }
}
//using recursion and backtracking
void inserAtBottom(stack<int>&st1,int ele){
    stack<int>st2;
      //base case
  if(st1.empty()) {
    st1.push(ele);
    return;
  } 
  //1 case mera
  int topE = st1.top();
  st1.pop();
  //baaaki rec
  inserAtBottom(st1,ele);
  //BT
  st1.push(topE);
}
int main(){
    stack<int>st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    // deleteMiddleEle(st);
    // cout<<endl;
    // deleMiddle(st,st.size(),0);
    // cout<<endl;
    insertBottom(st,7);
    // vector<int>temp;
    while(!st.empty()) {
        int temp=st.top();
        cout<<temp<<" ";
        st.pop();
    }
    // for(int i=0;i<temp.size();i++){
    //     cout<<temp[i]<<" ";
    // }
    return 0;
  
}