
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;


/*//&-----------------------------------------Brrute force -->suficiaent for small input or small value of k-------------*/
vector<int> findMax(vector<int>& arr, int k) {
    vector<int>ans;
    int n=arr.size();
    if(k>n){
        return {};
    }
    if(k==n){
        int max_ele=*max_element(arr.begin(),arr.end());
        ans.push_back(max_ele);
        return ans;
    }
    for(int i=0;i<=n-k;i++){  //O(n)
        int max_ele=arr[i];
        for(int j=1;j<i+k;j++){  //O(k)
            max_ele=max(max_ele,arr[j]);
        }
        ans.push_back(max_ele);
    }
    return ans;
/*Time complexity: O(n*k)---
------space complexity: O(n)--------------------------------------------------------------------------------------------------*/
}


vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        int i = 0, j = 0;
        int max_ele = INT_MIN;

        // edge cases
        if (k > n) {
            return ans;
        }
        if (k == n) {
            int max_ele = *max_element(nums.begin(), nums.end());
            ans.push_back(max_ele);
            return ans;
        }

        while (j < n) {
            // Update the max element in the current window
            max_ele = max(max_ele, nums[j]);

            // If window size is less than k, just move the end pointer
            if (j - i + 1 < k) {
                j++;
            } else if (j - i + 1 == k) {
                // When window size equals k
                ans.push_back(max_ele);

                // Slide the window
                if (nums[i] == max_ele) {
                    // If the outgoing element is the max, we need to find the new max
                    max_ele = INT_MIN;
                    for (int p = i + 1; p <= j; p++) {
                        max_ele = max(max_ele, nums[p]);
                    }
                }
                i++;
                j++;
                if (j < n) {
                    max_ele = max(max_ele, nums[j]);
                }
            }
        }

        return ans;
}



int main() {

    vector<int>arr={1,3,-1,-3,5,3,6,7};
    int k=3;
    vector<int> result = findMax(arr, k);
    for(auto &ch:result){
        cout<<ch<<" ";
    }
    cout<<endl;
   


}

