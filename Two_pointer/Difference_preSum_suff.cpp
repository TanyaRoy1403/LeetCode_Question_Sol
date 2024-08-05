#include<iostream>
#include<vector>
using namespace std;
/*Given a 0-indexed integer array nums, find a 0-indexed integer array answer where:

answer.length == nums.length.
answer[i] = |leftSum[i] - rightSum[i]|.*/

vector<int> solve(vector<int>&arr){
    int n=arr.size();
    vector<int>ans(n,0);

    
    // vector<int>preSUm(n,0);
    // preSUm[0]=arr[0];
    // for(int i=1;i<n;i++){
    //     preSUm[i]=preSUm[i-1]+arr[i-1];  //^preSum-->without including i
    //     // preSUm[i]=preSUm[i-1]+arr[i];  //^preSum--> including i
    // }

    // //^suff-->withou including i
    // vector<int>suff(n,0);
    // suff[n-1]=arr[n-1];
    // for(int i=n-2;i>=0;i--){
    //     suff[i]=suff[i+1]+arr[i+1]; //^preSum-->without including i
    //     // suff[i]=suff[i+1]+arr[i];  //^preSum--> including i
    // }
    // for(int i=0;i<n;i++){
    //     ans[i]=abs(preSUm[i]-suff[i]);
    // }
    // return ans;

/* we can reduce space complexity*/
int total_sum=0;
for(int i=0;i<n;i++){
    total_sum+=arr[i];
 }
 int preSum=0;
 for(int i=0;i<n;i++){
    total_sum-=arr[i];
    ans[i]=abs(preSum-total_sum);
    preSum+=arr[i];
 }
 return ans;
}




int main(){
    vector<int>arr={10,4,8,3};
    vector<int>ans=solve(arr);
    for(auto &ch:ans){
        cout<<ch<<" ";
    }
}