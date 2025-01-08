#include <iostream>
#include <vector>
using namespace std;    

int maxScoreSightseeingPair(vector<int>& values) {
    int n = values.size();
    int maxScore = 0;
    int maxLeft = values[0];
    for (int i = 1; i < n; i++) {
        maxScore = max(maxScore, maxLeft + values[i] - i);
        maxLeft = max(maxLeft, values[i] + i);
    }
    return maxScore;
}

int main() {
    vector<int> values = {7, 8, 8, 10};
    cout << maxScoreSightseeingPair(values) << endl;
    return 0;
}