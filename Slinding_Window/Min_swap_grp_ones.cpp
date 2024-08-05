
#include <vector>
#include <numeric>
#include <algorithm>
#include <climits>
#include <iostream>
using namespace std;
/*A circular array is defined as an array where we consider the first element and the last element to be adjacent.

Given a binary circular array nums, return the minimum number of swaps required to group all 1's present in 
the array together at any location.Input: nums = [1,1,0,0,1]
Output: 0*/


int solve(std::vector<int>& arr) {
    int n = arr.size();
    
    // Calculate the total number of 1's in the array
    int countOnes = accumulate(arr.begin(), arr.end(), 0);
    int i = 0, j = 0;
    int curr_ones = 0;
    int max_ones = INT_MIN;
    
    // Traverse the array in a circular manner using modulo operation
    while (j < 2 * n) {
        if (arr[j % n] == 1) {
            curr_ones++;
        }
        
        // When the window size matches the total count of 1's
        if (j - i + 1 == countOnes) {
            max_ones = max(max_ones, curr_ones);
            if (arr[i % n] == 1) {
                curr_ones--;
            }
            i++;
        }
        
        j++;
    }
    
    return countOnes - max_ones;
}

int main() {
    std::vector<int> arr = {1,1,0,0,1};
    std::cout << solve(arr);
    return 0;
}
