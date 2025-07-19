#include<iostream>
#include<vector>
#include<algorithm>
using  namespace std;
//search space ka question 

/*You are given a 0-indexed array nums comprising of n non-negative integers.
In one operation, you must:
Choose an integer i such that 1 <= i < n and nums[i] > 0.
Decrease nums[i] by 1.
Increase nums[i - 1] by 1.
Return the minimum possible value of the maximum integer of nums after performing any number of operations.*/

//approach 
//step 1: define search space
//step 2: apply binary search
  bool isPossible(vector<int>& nums, int maxVal) {
        long long sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (sum > (long long)(i + 1) * maxVal) return false;
        }
        return true;
}
 int minimizeArrayValue(vector<int>& nums) {
    int n=nums.size();
    int low = 0, high = *max_element(nums.begin(), nums.end()), ans = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(nums, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;   
}
int main(){
    vector<int>arr={3,7,1,6};
    cout<<minimizeArrayValue(arr);
}
