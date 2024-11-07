#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*You are given m arr, where each array is sorted in ascending order.

You can pick up two integers from two different arr (each array picks one) and calculate the distance. 
We define the distance between two integers a and b to be their absolute difference |a - b|.

Return the maximum distance.*/
 

int solve(vector<vector<int>>& arr) {
    // Initialize min_ele and max_ele using the first subarray
    int min_ele = arr[0].front();
    int max_ele = arr[0].back();
    int ans = 0;

    // Run loop from the second array onwards
    for (int i = 1; i < arr.size(); i++) {
        int curr_min = arr[i].front();
        int curr_max = arr[i].back();

        // Update the result
        ans = max({ans, abs(max_ele - curr_min), abs(curr_max - min_ele)});

        // Update min_ele and max_ele after using them for comparison
        min_ele = min(min_ele, curr_min);
        max_ele = max(max_ele, curr_max);
    }
    return ans;
}

int main() {
    vector<vector<int>> arr = {{1, 2, 3}, {4, 5}, {1, 2, 3}};
    cout << solve(arr);
    return 0;
}
