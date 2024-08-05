#include <iostream>
#include <vector>
#include <unordered_map>
#include<algorithm>
using namespace std;

 int solve(vector<int>& arr, int n) {
    int count = 0;
    // unordered_map<int, int> freq;

    // // Count the frequency of each element in arr
    // for (int num : arr) {
    //     freq[num]++;
    // }
    // for(auto &it:freq){
    //     count+=(it.second/2)*2;
    // } 
    int MAX_ARTICLE = *max_element(arr.begin(), arr.end());

    vector<int> ans(MAX_ARTICLE + 1, 0); 

    // Count the frequency of each element in the array
    for (auto &it : arr) {
        ans[it]++;
    }

    // Sum the even contributions based on the counts
    for (int i = 0; i < ans.size(); ++i) {
        count += (ans[i] / 2) * 2;
    }


    return count;
}

 int main() {
    vector<int> arr = {10, 10, 10, 20, 20, 10, 20};
    int n = 7;
    cout << solve(arr, n) << endl;

    return 0;
}
