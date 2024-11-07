#include<iostream>
#include<stack>
#include<vector>
using namespace std;

//online stock span
//concept-->nearest greatest to left(prev)
vector<int> prevGreatereleIndex(vector<int>&arr){
    stack<int>st;
    // st.push(-1);
    vector<int>preAns(arr.size());
    for(int i=0;i<arr.size();i++){
        int curr_ele=arr[i];
        while(!st.empty()&&arr[st.top()]<=curr_ele){  //must be strictly greater
            st.pop();
        }
        if(st.empty()){
            preAns[i]=i+1;
        }
        else{
            preAns[i]=i-st.top();  //st.top()-- prevgrater ele ka index
        }
        st.push(i);
    }
    return preAns;
}

int main(){
    vector<int>arr={100,80,60,70,60,75,85};
    vector<int>ans=prevGreatereleIndex(arr);
    for(auto &ch:ans){
        cout<<ch<<" ";
    }
}