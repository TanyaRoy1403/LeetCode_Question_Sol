#include<iostream>
#include<vector>
using namespace std;
/*--Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. 
Then return the number of elements in nums which are not equal to val.

Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the elements which are not equal to val.
 The remaining elements of nums are not important as well as the size of nums.
Return k.--Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_,_]--*/

int remove_ele(vector<int>&arr,int val){
        //idx-->to point ele whose value is not equal to val also count the no of ele
        int idx=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]!=val){
                arr[idx]=arr[i];
                idx++;
            }
        }
        return idx;
/*-------Time complexity:O(n)
Space complexity:O(1)-----*/

}

int main(){
    vector<int>arr={3,2,2,3};
    int val=3;
    cout<<remove_ele(arr,val);
}
