#include <iostream>
#include <vector>
#include <string>

using namespace std;
/*You are given an m x n integer array grid where grid[i][j] could be:

1 representing the starting square. There is exactly one starting square.
2 representing the ending square. There is exactly one ending square.
0 representing empty squares we can walk over.
-1 representing obstacles that we cannot walk over.
Return the number of 4-directional walks from the starting square to the ending square, 
that walk over every non-obstacle square exactly once.*/





//^steps
   //first find starting point
    //find number of nonObstacles cell(either 0,2,1)
    //travers and find target 
    //if target found move forward and make sure that total count of nonOBS is equl to curr_coount and mark this cell as visited
    // not found backtrack and in favable position where 0 is cover
    //and mark piche wala cell as 0


//!globally declaration
    int m, n;
    int nonOBS;
    int result = 0;
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
void backtrack(vector<vector<int>>& grid, int curr_count, int i, int j) {
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == -1) {
            return;
        }
        
        if(grid[i][j] == 2) {
            if(curr_count == nonOBS) {
                result++;
            }
            return;
        }
        
        
        grid[i][j] = -1;
        for(vector<int> dir:directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            backtrack(grid, curr_count+1, new_i, new_j);
        }
        grid[i][j] = 0;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        nonOBS = 1;
        result = 0;
         int curr_count = 0; 
        
        int start_x = 0;
        int start_y = 0;
        
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j] == 0)
                    nonOBS++;
                
                if(grid[i][j] == 1) {
                    start_x = i;
                    start_y = j;
                }
            }
        }
        
       
        
        backtrack(grid, curr_count, start_x, start_y);
        
        return result;
    }

int main(){
    vector<vector<int>>grid={{1,0,0,0},{0,0,0,0},{0,0,0,2}};
    cout<<uniquePathsIII(grid);
}