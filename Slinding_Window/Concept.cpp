#include<bits/stdc++.h>
using namespace std;

// vector<int> max_subarr(vector<int>& arr, int k) {
//     int i = 0;
//     int j = 0;
//     int n = arr.size();
//     int max_sum = INT_MIN;
//     int sum = 0;
//     vector<int> result;

//     while (j < n) {
//         sum += arr[j];

//         if (j - i + 1 < k) {
//             j++;
//         } else if (j - i + 1 == k) {
//             if (sum > max_sum) {
//                 max_sum = sum;
//                 result = vector<int>(arr.begin() + i, arr.begin() + j + 1);
//             }
//             sum -= arr[i];
//             i++;
//             j++;
//         }
//     }

//     return result;
// }


int max_subarr(vector<int>& arr, int k) {
    int i = 0;
    int j = 0;
    int n = arr.size();
    int max_sum = INT_MIN;
    int sum = 0;

    while (j < n) {
        sum += arr[j];

        if (j - i + 1 < k) {
            j++;
        } else if (j - i + 1 == k) {
            max_sum=max(max_sum,sum);
      
            sum -= arr[i];
            i++;
            j++;
        }
    }

    return max_sum;
}

int main() {
    vector<int> arr = {2,5,1,8,2,9,1};
    int k = 3;
    // vector<int> result = max_subarr(arr, k);
    // cout << "The subarray with the maximum sum of size " << k << " is: ";
    // for (int x : result) {
    //     cout << x << " ";
    // }
    cout<<max_subarr(arr,k);
    cout << endl;
    return 0;
}


