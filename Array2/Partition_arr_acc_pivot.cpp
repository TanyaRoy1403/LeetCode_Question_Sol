#include<iostream>
#include<vector>
using namespace std;
/*--You are given a 0-indexed integer array nums and an integer pivot. Rearrange nums such that the following conditions are satisfied:

Every element less than pivot appears before every element greater than pivot.
Every element equal to pivot appears in between the elements less than and greater than pivot.
The relative order of the elements less than pivot and the elements greater than pivot is maintained.

More formally, consider every pi, pj where pi is the new position of the ith element and pj is the new position of the jth element. 
For elements less than pivot, if i < j and nums[i] < pivot and nums[j] < pivot, then pi < pj. Similarly for elements greater than pivot, 
if i < j and nums[i] > pivot and nums[j] > pivot, then pi < pj.
Return nums after the rearrangement.Input: nums = [9,12,5,10,14,3,10], pivot = 10
Output: [9,5,3,10,10,12,14]--*/

//Brute force

vector<int> partition_arr(vector<int>&arr,int pivot){
    vector<int>less;
    vector<int>equal;
    vector<int>greater;
    vector<int>result;
    for(auto &it:arr){
        if(it<pivot){
            less.push_back(it);
        }
    }
    for(auto &it:arr){
        if(it==pivot){
            equal.push_back(it);
        }
    }
    for(auto &it:arr){
        if(it>pivot){
            greater.push_back(it);
        }
    }
    for(auto i:less){
        result.push_back(i);
    }
    for(auto i:equal){
        result.push_back(i);
    }
    for(auto i:greater){
        result.push_back(i);
    }
    return result;
/*-------Time complexity:O(N)
Space complexity:O(N)--------*/
}

//optimal solution----
vector<int> part(vector<int>&arr,int pivot){
    vector<int>ans;
    //smaller element
    for(auto &it:arr){
        if(it<pivot)
        ans.push_back(it);
    }
    //equal element
    for(auto &it:arr){
        if(it==pivot)
        ans.push_back(it);
    }
    //bigger element
    for(auto &it:arr){
        if(it>pivot)
        ans.push_back(it);
    }
        return ans;
/*we optimise only in input and output sense -->all have same t.c and s.c */
/*--------------------------------------------------------------------------------------------*/
        // vector<int> smaller, equal, larger;

        // // Single pass through the nums array
        // for (auto &it : nums) {
        //     if (it < pivot)
        //         smaller.push_back(it);
        //     else if (it == pivot)
        //         equal.push_back(it);
        //     else
        //         larger.push_back(it);
        // }

        // // Concatenate the results
        // vector<int> ans;
        // ans.reserve(nums.size());
        // ans.insert(ans.end(), smaller.begin(), smaller.end());
        // ans.insert(ans.end(), equal.begin(), equal.end());
        // ans.insert(ans.end(), larger.begin(), larger.end());

        // return ans;
/*-----------------------------------------------------------------------------------------------*/

}
int main(){
    vector<int>arr={9,12,5,10,14,3,10};
    int pivot=10;
    vector<int>ans=part(arr,pivot);
    for(auto &it:ans){
        cout<<it<<" ";
    }
}