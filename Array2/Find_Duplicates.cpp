#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
vector<int> find_dup(vector<int>&arr){
//     unordered_map<int,int>mp;  //O(1)-->T.C
    vector<int>ans; //O(1)
//     for(auto &it:arr){
//         mp[it]++;
//     }
//     for(auto &a:mp){  //O(N)
//         if(a.second>1){
//             ans.push_back(a.first);
//         }
//     }
    // sort(ans.begin(),ans.end()); //O(KlongK) (K duplicate)
    sort(arr.begin(),arr.end());
    // if(ans.empty())
        // return ans;
    //Overall-->O(N+KlongK)


    for(int i=1;i<arr.size();i++){
        if(arr[i-1]==arr[i]){
            ans.push_back(arr[i]);
        }
    }
    return ans;
}
int main(){
    vector<int>arr={4,3,2,7,8,2,3,1};
    vector<int>ans=find_dup(arr);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}