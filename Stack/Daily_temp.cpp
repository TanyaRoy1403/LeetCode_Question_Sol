#include<iostream>
#include<vector>
#include<stack>
using namespace std;

/*Given an array of integers temperatures represents the daily temperatures, 
return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. 
If there is no future day for which this is possible, keep answer[i] == 0 instead.*/


vector<int> solveBruteForce(vector<int>&arr){
    int n=arr.size();
    vector<int>ans(n,0); //no extra space
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]<arr[j]){
                ans[i]=abs(j-i);
                break;
            }
        }
    }
  return ans;
}
//optimal solution
void nextGreatereleIndex(vector<int>&arr,vector<int>&nextAns){
    stack<int>st;
    st.push(arr.size());
    for(int i=arr.size()-1;i>=0;i--){
        int curr_ele=arr[i];
        while(st.top()!=arr.size()&&arr[st.top()]<=curr_ele){  //yaha pr  hi bss change h baaki same as nextSmall jaisa hi h
            st.pop();
        }
        if(st.top() == arr.size()) {
            nextAns[i] = 0;  // No warmer day
        } else {
            nextAns[i] = st.top() - i;  // Calculate the difference in indices
        }
        st.push(i);
    }
}
vector<int> solveOptimal(vector<int>&arr){
    vector<int>nextAns(arr.size(),0);
    nextGreatereleIndex(arr,nextAns);
    return nextAns;
}
int main(){
    vector<int>arr={73,74,75,71,69,72,76,73};
    vector<int>ans=solveBruteForce(arr);
    for(auto &ch:ans){
        cout<<ch<<" ";
    }
    cout<<endl;

    vector<int>ans1=solveOptimal(arr);
    for(auto&ch:ans1){
        cout<<ch<<" ";
    }
    return 0;
}