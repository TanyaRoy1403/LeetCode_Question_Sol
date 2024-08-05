#include<bits/stdc++.h>
using namespace std;
///using mapping ,count array
vector<int> find_duplicate(vector<int>&arr,int n){
    vector<int>ans;
    sort(arr.begin(),arr.end());
//    unordered_map<int,int>mp;
//    ///count occ
//    for(auto it:arr){
//        mp[it]++;
//    }
//    ///collect key whose value/count is greter than 1
//    for(auto x:mp){
//        if(x.second>1){
//            ans.push_back(x.first);
//        }
//    }
//    sort(ans.begin(),ans.end());
//    return ans;
//}
///brute force


for(int i=1;i<n-1;++i){
    if(arr[i]==arr[i-1]){
        ans.push_back(arr[i]);
++i;
    }
    }
    return ans;
}



int main(){
    vector<int>arr={4,3,2,7,8,2,3,1};
    int n=8;
    vector<int>ans=find_duplicate(arr,n);
    for(auto it:ans){
        cout<<it<<" ";
    }
}

