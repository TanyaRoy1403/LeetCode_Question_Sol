#include<iostream>
#include<vector>
using namespace std;
void backtrack(vector<int>&nums,int i,vector<vector<int>>&ans){
    if(i>=nums.size()){
        ans.push_back(nums);
        return ;
    }
    for(int j=i;j<nums.size();j++){
        swap(nums[i],nums[j]);
        backtrack(nums,i+1,ans);
        swap(nums[i],nums[j]);
    }
}


vector<vector<int>> findPermutation(vector<int>&nums){
    int i=0;
    vector<vector<int>>ans;
    backtrack(nums,i,ans);
    return ans;
}
int main(){
    vector<int>nums={1,2,3};
    vector<vector<int>>ans=findPermutation(nums);
    for(auto &ch:ans){
        for(auto &it:ch){
            cout<<it;
        }

        cout<<endl;
    }
}