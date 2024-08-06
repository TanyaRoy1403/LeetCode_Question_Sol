#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
/*You are given the array nums consisting of n positive integers. You computed the sum of all non-empty continuous subarrays from the array and 
then sorted them in non-decreasing order, creating a new array of n * (n + 1) / 2 numbers.

Return the sum of the numbers from index left to index right (indexed from 1), inclusive, in the new array. 
Since the answer can be a huge number return it modulo 109 + 7.Input: nums = [1,2,3,4], n = 4, left = 1, right = 5
Output: 13*/

using namespace std;
const int MOD =1e9+7;

int solve(vector<int>&arr,int left,int right){
    int n=arr.size();
    // int m=n*(n+1)/2;
    vector<int>ans;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            ans.push_back(sum);
      
        }
    }
    sort(ans.begin(),ans.end());
    int final_sum=0;
    for(int i=left-1;i<right;i++){
        final_sum=(final_sum+ans[i])%MOD;
    }

    return final_sum;
}
int main(){
    vector<int>arr={1,2,3,4};
    int left=1;
    int right=5;
    cout<<solve(arr,left,right);
}