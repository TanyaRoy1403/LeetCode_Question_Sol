#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<climits>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> ans;
    int n = nums.size();
    int i = 0;
    while (i <= n - k) {
        int maxInt = INT_MIN;
        int j=i;
        while(j<i+k){
            maxInt=max(maxInt,nums[j]);
            j++;
        }
        ans.push_back(maxInt);
        i++;
    }
    return ans;
}
//optimized approach
vector<int> solve(vector<int>&nums,int k){
    priority_queue<pair<int,int>>pq;
    vector<int>ans;
    for(int i=0;i<k;i++){
        pq.push({nums[i],i});
    }
    ans.push_back(pq.top().first);
    for(int i=k;i<nums.size();i++){
        pq.push({nums[i],i});
        while(pq.top().second<=i-k){
            pq.pop();
        }
        ans.push_back(pq.top().first);
    }
    return ans;

}
int main(){
    vector<int>nums={1,3,-1,-3,5,3,6,7};
    int k=3;
    vector<int> ans = maxSlidingWindow(nums, k);
    for(auto &ele:ans){
        cout<<ele<<" ";
    }
    cout<<endl;
    vector<int> ans1 = solve(nums, k);
    for(auto &ele:ans1){
        cout<<ele<<" ";
    }
    return 0;
}


// Time Complexity: O(n*k)
// The outer while loop runs (n-k+1) times, and the inner for loop runs k times for each iteration of the outer loop.
// Hence, the overall time complexity is O(n*k).
// Space Complexity: O(1)


