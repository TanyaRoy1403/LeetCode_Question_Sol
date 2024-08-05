#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
// int search(vector<int>& nums, int target) {
// 		int l = 0, r = nums.size() - 1;
// 		while(l <= r){
// 			int mid = l + (r-l)/2;
// 			if(nums[mid] == target) return mid;
// 			else if(nums[l]>=nums[mid]){
// 				if(nums[l]<=target && target<nums[mid]) r = mid-1;
// 				else l = mid+1;
// 			}
// 			else{
// 				if(nums[mid]<target && target<=nums[r]) l = mid+1;
// 				else r = mid-1;
// 			}
// 		}
// 		return -1; // No need to debug this line.
// 	}
// int mySqrt(int x) {
//         int first = 1, last = x;
//     int ans=0;
//         if (x == 0)
//             return x;
//         while (first <= last) {
//             int mid = first + (last - first) / 2;
//             int val=x/mid;
//             if (mid  == x / mid)
//                 return mid;
//             else if (mid > x / mid) {
//                 last = mid-1;
//             }
//             else {
//                 ans=mid;
//                 first = mid+1;
//             }
//         }
//         return ans;
// }

int findMin(vector<int>& nums) {
        int start = 0, end = nums.size()-1, ans = start;
        while(nums[start] > nums[end]) {
            int mid = (start + end) >>1;
            if(nums[mid] <= nums[start] && nums[mid] <= nums[end]) 
                end = mid;
            else if(nums[mid] >= nums[start] && nums[mid] >= nums[end])
                start = mid;          
            else return nums[mid];
            ans = start;
        }
        return nums[ans];
    }
int main(){
  vector<int>nums={5,20,70,50,90,100};
  cout<<findMin(nums);

    
}