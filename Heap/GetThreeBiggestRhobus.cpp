#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool checkBounds(int i, int j, int k, int m, int n) {
        return i - k >= 0 && i + k < m && j - k >= 0 && j + k < n;
    }

int getAllSum(vector<vector<int>>& grid, int i, int j, int k) {
    if (k == 0) return grid[i][j];

    int sum = 0;

    // Top to right (↘)
    for (int d = 0; d < k; ++d) {
        sum += grid[i - k + d][j + d];
    }

    // Right to bottom (↙)
    for (int d = 0; d < k; ++d) {
        sum += grid[i + d][j + k - d];
    }

    // Bottom to left (↖)
    for (int d = 0; d < k; ++d) {
        sum += grid[i + k - d][j - d];
    }

    // Left to top (↗)
    for (int d = 0; d < k; ++d) {
        sum += grid[i - d][j - k + d];
    }

    return sum;
}


vector<int> getBiggestThree(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    priority_queue<int> pq;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            pq.push(grid[i][j]); // size 0 rhombus
            for (int k = 1; checkBounds(i, j, k, m, n); ++k) {
                int sum = getAllSum(grid, i, j, k);
                pq.push(sum);
            }
        }
    }
    vector<int> result;
    while (!pq.empty() && result.size() < 3) {
        int top = pq.top();
        pq.pop();
        if (result.empty() || result.back() != top)
            result.push_back(top);
    }

        return result;
    }


//yeh jada optimise nhi h  ..optimisee solution hoga jb hm prefixsum ka use kryege diagonols ka sum krhne ke liye 

int main(){
    vector<vector<int>>grid={{3,4,5,1,3},{3,3,4,2,3},{20,30,200,40,10},{1,5,5,4,1},{4,3,2,2,5}};
    vector<int>ans=getBiggestThree(grid);
    for(auto &ch:ans){
        cout<<ch<<" ";
    }
    return 0;
}