#include <iostream>
#include <vector>

using namespace std;

vector<int> suffixSum_including_currele_inplace(vector<int>& arr) {
    int n = arr.size();
    int total_sum = 0;

    for (int i = 0; i < n; i++) {
        total_sum += arr[i];
    }


    for (int i = 0; i < n; i++) {
        int suff_sum = total_sum; 
        arr[i] = suff_sum;        
        total_sum -= arr[i];      
    }

    return arr;
}

vector<int> suffixSum_excluding_currele_inplace(vector<int>& arr) {
    int n = arr.size();
    int total_sum = 0;

    // Step 1: Calculate the total sum of the array
    for (int i = 0; i < n; i++) {
        total_sum += arr[i];
    }

    // Step 2: Compute suffix sums excluding the current element
    for (int i = 0; i < n; i++) {
        int suff_sum = total_sum - arr[i]; // suffix_sum excludes the current element
        arr[i] = suff_sum; // Update the current element with suffix sum excluding itself
    }

    return arr;
}
int main() {
    vector<int> arr = {10, 4, 8, 3};
    vector<int> ans = suffixSum_excluding_currele_inplace(arr);
    cout << "Suffix Sum Including current element (in place): ";
    for (const auto& ch : ans) {
        cout << ch << " ";
    }
    return 0;
}
