#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> nextSmaller(vector<int>&arr){
    stack<int>st;
    st.push(-1);
    vector<int>ans(arr.size());
    for(int i=arr.size()-1;i>=0;i--){
        int curr_ele=arr[i];
        while(st.top()>=curr_ele){  //~we can avoid to push -1 in stack intially by simple checking the !st.empty() in whilw loop
            st.pop();
        }
        ans[i]=st.top();
        st.push(curr_ele); 
    }
    return ans;
}

vector<int> prevSmaller(vector<int>&arr){
    stack<int>st;
    st.push(-1);
    vector<int>ans(arr.size());
    for(int i=0;i<arr.size();i++){
        int curr_ele=arr[i];
        while(st.top()>curr_ele){
            st.pop();
        }
        ans[i]=st.top();
        st.push(curr_ele); 
    }
    return ans;
}
int main(){ 
    vector<int>arr={8,4,6,2,3};
    vector<int>ans=nextSmaller(arr);
    for(auto&it:ans){

        cout<<it<<" ";
    }
    cout<<endl;
    vector<int> arr2={8,4,6,2,3};
    vector<int>ans2=prevSmaller(arr2);
    for(auto&it:ans2){
        cout<<it<<" ";
    }


    return 0;
}