#include<bits/stdc++.h>
using namespace std;
// vector<int> remove_du(vector<int>&arr){
//     set<int>st;
//     vector<int>ans;
//     for(int i=0;i<arr.size();i++){
//         if(st.find(arr[i])==st.end()){
//             st.insert(arr[i]);
//             ans.push_back(arr[i]);
//         }else{
//             st.erase(arr[i]);
//         }
//     }
//     return ans;
// }
int main(){
    // vector<int>arr={1,1,2};
    // vector<int>ans=remove_du(arr);
    // for(auto &it:ans){
    //     cout<<it<<" ";
    // 
    vector<int>arr={30,90,100};
    sort(arr.begin(),arr.end(),greater<int>());
    for(auto it:arr){
        cout<<it<<" ";
    }


}