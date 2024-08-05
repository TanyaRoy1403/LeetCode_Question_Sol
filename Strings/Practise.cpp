#include <iostream>
#include <vector>
using namespace std;

vector<int> solve(string s) {
    vector<int> count_arr(26, 0); // Use vector<int> instead of vector<char>
    for (auto &ch : s) {
        int idx = ch - 'a';
        count_arr[idx]++;
    }
    return count_arr;
}

int main() {
    string s = "tanya";
    vector<int> ans = solve(s); // Use vector<int> instead of vector<char>
    for (auto &it : ans) {
        cout << it << " "; // Print each count followed by a space for readability
    }
    return 0;
}
