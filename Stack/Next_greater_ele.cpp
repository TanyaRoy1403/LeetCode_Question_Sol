#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/*GFG*/
/*Given an array arr[ ] of n elements, the task is to find the next greater element for each element of the array in order of their appearance in the array. 
Next greater element of an element in the array is the nearest element on the right which is greater than the current element.
If there does not exist next greater of current element, then next greater element for current element is -1. 
For example, next greater of the last element is always -1.*/

vector<int>nextGreaterele(vector<int>&arr){
    stack<int>st;
    vector<int>ans(arr.size());
    for(int i=arr.size()-1;i>=0;i--){
        int curr_ele=arr[i];
        while(!st.empty()&&st.top()<=curr_ele){  //yaha pr  hi bss change h baaki same as nextSmall jaisa hi h
            st.pop();
        }
        if(st.empty()){
            ans[i]=-1;
        }
        else{
            ans[i]=st.top();
        }
        st.push(curr_ele);
    }  
    return ans;
}
vector<int> prevGreaterele(vector<int>&arr){
    stack<int>st;
    st.push(-1);
    vector<int>preAns(arr.size());
    for(int i=0;i<arr.size();i++){
        int curr_ele=arr[i];
        while(st.top()!=-1&&st.top()<=curr_ele){  //must be strictly greater
            st.pop();
        }
        preAns[i]=st.top();
        st.push(curr_ele);
    }
    return preAns;
}

int main(){
    vector<int>arr={6,8,0,1,3};
    vector<int>ans=nextGreaterele(arr);
    for(auto &ch:ans){
        cout<<ch<<" ";
    }
    cout<<endl;
    vector<int>arr1={6,8,0,1,3};
    vector<int>ans1=prevGreaterele(arr1);
    for(auto&ch:ans1){
        cout<<ch<<" ";
    }

}