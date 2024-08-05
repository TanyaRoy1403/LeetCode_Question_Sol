
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*You are given a 0-indexed array nums of size n consisting of non-negative integers.

You need to apply n - 1 operations to this array where, in the ith operation (0-indexed),
 you will apply the following on the ith element of nums:

If nums[i] == nums[i + 1], then multiply nums[i] by 2 and set nums[i + 1] to 0. Otherwise, you skip this operation.
After performing all the operations, shift all the 0's to the end of the array.

For example, the array [1,0,2,0,0,1] after shifting all its 0's to the end, is [1,2,1,0,0,0].
Return the resulting array.

Note :that the operations are applied sequentially, not all at once.*/
vector<int>apply(vector<int>&nums){
    int n=nums.size();
    for(int i=0;i<n-1;i++){
        if(nums[i]==nums[i+1]){
            nums[i]*=2;
            nums[i+1]=0;
            
        }
    }

    
    int k = 0; // Index to place the next non-zero element
    for (int i = 0; i < n; ++i) {
        if (nums[i] != 0) {
            nums[k++] = nums[i];
        }
    }

    // Fill the rest with zeros
    while (k < n) {
        nums[k++] = 0;
    }

/*---------------------------------------------------------------------------------------------*/
    // int i=0;                                                                               
    // int j=n-1;
    // while (i < j) {
    //     if (nums[i] == 0 && nums[j] != 0) {
    //         swap(nums[i], nums[j]);
    //         i++;
    //         j--;
    //     } else {
    //         if (nums[i] != 0) i++;
    //         if (nums[j] == 0) j--;
    //     }
    // }
//it is giving diff order
 /*-----------------------------------------------------------------------------------------------*/
 
    return nums;

/*------------Time Complexity: O(n)
Space Complexity: O(1)------------------*/
}
int main(){
    vector<int>nums={1,0,2,0,0,1};
    vector<int>ans=apply(nums);
    for(auto &it:ans){
        cout<<it<<" ";
    }
}