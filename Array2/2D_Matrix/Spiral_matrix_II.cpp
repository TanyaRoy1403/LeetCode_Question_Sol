#include<iostream>
#include<vector>
using namespace std;

/* Given an n x n matrix, fill it in spiral order. */

vector<vector<int>> spiralOrder(int n) {
    vector<vector<int>> ans(n, vector<int>(n));  // Initialize a 2D vector with size n x n
    int top_row = 0;
    int down_row = n - 1;
    int first_col = 0;
    int last_col = n - 1;
    int count = 1;
    int direction = 0;  // 0 = left to right, 1 = top to bottom, 2 = right to left, 3 = bottom to top
    
    while (top_row <= down_row && first_col <= last_col) {
        if (direction == 0) {  // Move left to right
            for (int i = first_col; i <= last_col; i++) {
                ans[top_row][i] = count;
                count++;
            }
            top_row++;  // move the top row down
        } 
        else if (direction == 1) {  // Move top to bottom
            for (int i = top_row; i <= down_row; i++) {
                ans[i][last_col] = count;
                count++;
            }
            last_col--;  // move the last column left
        } 
        else if (direction == 2) {  // Move right to left
            for (int i = last_col; i >= first_col; i--) {
                ans[down_row][i] = count;
                count++;
            }
            down_row--;  // move the bottom row up
        } 
        else if (direction == 3) {  // Move bottom to top
            for (int i = down_row; i >= top_row; i--) {
                ans[i][first_col] = count;
                count++;
            }
            first_col++;  // move the first column right
        }
        direction = (direction + 1) % 4;
    }
    
    return ans;
}

int main() {
    int n=3;
    vector<vector<int>> result = spiralOrder(n);
    for (const auto& row : result) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
