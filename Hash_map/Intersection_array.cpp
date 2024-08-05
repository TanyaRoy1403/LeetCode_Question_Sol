#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
vector<int> solve(vector<int>&nums1,vector<int>&nums2){
    int n=nums1.size();
    int m=nums2.size();
    unordered_map<int,int>mp;
    vector<int>ans;
    for(auto &it:nums1){
        mp[it]++;
    }
    for(int i=0;i<m;i++){
        if(mp.count(nums2[i])!=0){
            ans.push_back(nums2[i]);
            mp[nums2[i]]--;
        }
        if(mp[nums2[i]]==0){
            mp.erase(nums2[i]);
        }
    }
    return ans;
}
int main(){
    vector<int>nums1={4,9,5};
    vector<int>nums2={9,4,9,8,4};
    vector<int>ans=solve(nums1,nums2);
    for(auto&it:ans){
        cout<<it;
    }
}