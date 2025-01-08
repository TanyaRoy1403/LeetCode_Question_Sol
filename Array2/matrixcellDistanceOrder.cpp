#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
// You are given four integers row, cols, rCenter, and cCenter. 
// There is a rows x cols matrix and you are located at the cell (rCenter, cCenter).
// Return the coordinates of all cells in the matrix, sorted by their distance from (rCenter, cCenter) 
// from the smallest distance to the largest distance. 
// You may return the answer in any order that satisfies this condition.
// The distance between two cells (r1, c1) and (r2, c2) is |r1 - r2| + |c1 - c2|.


vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter){
    vector<vector<int>> result;
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            result.push_back({i, j});
        }
    }
    sort(result.begin(), result.end(), [rCenter, cCenter](vector<int>& a, vector<int>& b){
        return abs(a[0] - rCenter) + abs(a[1] - cCenter) < abs(b[0] - rCenter) + abs(b[1] - cCenter);
    });
    return result;
}
int main(){
    int rows = 2;
    int cols = 3;
    int rCenter = 1;
    int cCenter = 2;
    vector<vector<int>> result = allCellsDistOrder(rows, cols, rCenter, cCenter);
    for(int i=0; i<result.size(); i++){
        cout << result[i][0] << " " << result[i][1] << endl;
    }
    return 0;
}