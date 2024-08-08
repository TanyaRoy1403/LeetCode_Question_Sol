#include<iostream>
#include<vector>
using namespace std;
/*Given an m x n matrix, return all elements of the matrix in spiral order.*/

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size(); 
    if (m == 0) return {};  // handle empty matrix case
    int n = matrix[0].size(); 
    
    vector<int> ans;
    int top_row = 0;
    int down_row = m - 1;
    int first_col = 0;
    int last_col = n - 1;
    int direction = 0;  //* 0 = left to right, 1 = top to bottom, 2 = right to left, 3 = bottom to top
    
    while (top_row <= down_row && first_col <= last_col) {
        if (direction == 0) {  //* Move left to right
            for (int i = first_col; i <= last_col; i++) {
                ans.push_back(matrix[top_row][i]);
            }
            top_row++;  //*move the top row down
        } 
        else if (direction == 1) {  // Move top to bottom
            for (int i = top_row; i <= down_row; i++) {
                ans.push_back(matrix[i][last_col]);
            }
            last_col--;  //*move the last column left
        } 
        else if (direction == 2) {  // Move right to left
            for (int i = last_col; i >= first_col; i--) {
                ans.push_back(matrix[down_row][i]);
            }
            down_row--;  //*move the bottom row up
        } 
        else if (direction == 3) {  //* Move bottom to top
            for (int i = down_row; i >= top_row; i--) {
                ans.push_back(matrix[i][first_col]);
            }
            first_col++;  //*move the first column right
        }
        direction = (direction + 1) % 4;
    }
        
        return ans;
}