#include<iostream>
#include<vector>
#include<cmath>
#include<limits.h>
using namespace std;

int solve(vector<int>& arr) {
    int n = arr.size();
    vector<long long> pre(n);
    vector<long long> suff(n);
    
    // Calculate prefix sums
    pre[0] = arr[0];
    for(int i = 1; i < n; i++) {
        pre[i] = pre[i - 1] + arr[i];
    }
    
    // Calculate suffix sums
    suff[n - 1] = arr[n - 1];
    for(int i = n - 2; i >= 0; i--) {
        suff[i] = suff[i + 1] + arr[i];
    }
    
    int minIndex = 0;
    long long minAvgDiff = LLONG_MAX;

    for(int i = 0; i < n; i++) {
        long long leftAvg = pre[i] / (i + 1);
        long long rightAvg = (i == n - 1) ? 0 : suff[i + 1] / (n - i - 1);
        long long avgDiff = abs(leftAvg - rightAvg);

        if(avgDiff < minAvgDiff) {
            minAvgDiff = avgDiff;
            minIndex = i;
        }
    }
    
    return minIndex;
}


int solve2(vector<int>& arr) {
    int n = arr.size();
    long long totalSum = 0;
    
    // Calculate the total sum of the array
    for (int i = 0; i < n; i++) {
        totalSum += arr[i];
    }
    
    long long prefixSum = 0;
    long long minAvgDiff = LLONG_MAX;
    int minIndex = 0;
    
    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];
        long long leftAvg = prefixSum / (i + 1);
        long long rightSum = totalSum - prefixSum;
        long long rightAvg = (i == n - 1) ? 0 : rightSum / (n - i - 1);
        long long avgDiff = abs(leftAvg - rightAvg);
        
        if (avgDiff < minAvgDiff) {
            minAvgDiff = avgDiff;
            minIndex = i;
        }
    }
    
    return minIndex;
}


int main() {
    vector<int> nums = {2,5,3,9,5,3}; // Example input
    cout << "Index with the minimum average difference: " << solve(nums) << endl;
    cout << "Index with the minimum average difference: " << solve2(nums) << endl;
    return 0;
}
