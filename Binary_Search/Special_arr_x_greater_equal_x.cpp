#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*You are given an array nums of non-negative integers. nums is considered special if there exists a number x 
such that there are exactly x numbers in nums that are greater than or equal to x.

Notice that x does not have to be an element in nums.

Return x if the array is special, otherwise, return -1. It can be proven that if nums is special, the value for x is unique.*/

//^search space question

int first_greater_ele(vector<int>&nums,int target){
    int s=0;
    int e=nums.size();
    int idx=nums.size();
    while(s<=e){
        int mid=s+(e-s)/2;
        if(nums[mid]>=target){
            idx=mid;
            e=mid-1;
        }else{
            s=mid+1;
        }
    }
    return idx;
}

int find_x(vector<int>&nums){
    sort(begin(nums),end(nums));
    //khude ke index hi compare krege
    for(int i=1;i<=nums.size();i++){
        int k=first_greater_ele(nums,i);
        if((nums.size()-k)==i){
            return i;
        }
    }
    return -1;
}
int main(){
    vector<int>nums={3,5};
    cout<<find_x(nums);
}