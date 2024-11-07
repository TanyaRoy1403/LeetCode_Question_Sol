#include<iostream>
#include<vector>
#include<bitset>
using namespace std;

// Function to convert decimal numbers to binary strings
vector<string> decimal_binar(const vector<int>& arr) {
    vector<string> ans;  // Store binary numbers as strings
    for (const auto& num : arr) {
        bitset<8> binary(num);  // Convert the number to 8-bit binary
        ans.push_back(binary.to_string());  // Store the binary string
    }
    return ans;
}

// Function to solve the XOR queries on binary numbers
vector<int> solve(const vector<string>& arr, const vector<vector<int>>& que) {
    vector<int> result;
    
    for (const auto& q : que) {
        int xorSum = 0;
        for (int i = q[0]; i <= q[1]; i++) {
            // Convert binary string back to an integer using bitset
            bitset<8> binary(arr[i]);
            xorSum ^= (int)(binary.to_ulong());  // Convert bitset to unsigned long and XOR it
        }
        result.push_back(xorSum);
    }
    
    return result;
}

int main() {
    vector<int> arr = {1, 2, 3, 4};  // Example input
    vector<string> binaryArr = decimal_binar(arr);  // Convert to binary strings
    
    vector<vector<int>> queries = {{0, 1}, {1, 3}};  // Example queries
    vector<int> ans = solve(binaryArr, queries);  // Solve XOR queries
    
    for (const auto& x : ans) {
        cout << x << " ";  // Output results
    }
}
