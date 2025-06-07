#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long solve(vector<long long>& height, int n, long long m) {
    long long s = 0;
    long long e = *max_element(height.begin(), height.end());
    long long ans = 0;

    while (s <= e) {
        long long mid = s + (e - s) / 2;
        long long totalwood = 0;

        for (int i = 0; i < n; i++) {
            if (height[i] > mid)
                totalwood += (height[i] - mid);
        }

        if (totalwood >= m) {
            ans = mid;
            s = mid + 1;
        } else {
            e = mid - 1;
        }
    }

    return ans;
}

int main() {
    int n;
    long long m;
    cin >> n >> m;
    vector<long long> height(n);
    for (int i = 0; i < n; i++) {
        cin >> height[i];
    }
    cout << solve(height, n, m);
    return 0;
}
