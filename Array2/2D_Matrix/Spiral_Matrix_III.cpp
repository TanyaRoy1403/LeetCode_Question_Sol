#include<iostream>
#include<vector>
using namespace std;
/*You start at the cell (rStart, cStart) of an rows x cols grid facing east. 
The northwest corner is at the first row and column in the grid, and the southeast corner is at the last row and column.

You will walk in a clockwise spiral shape to visit every position in this grid. Whenever you move outside the grid's boundary, 
we continue our walk outside the grid (but may return to the grid boundary later.). Eventually, we reach all rows * cols spaces of the grid.

Return an array of coordinates representing the positions of the grid in the order you visited them.*/

vector<vector<int>> spiral_matrix(int rows, int cols, int rStart, int cStart){
    vector<vector<int>>result;

    vector<vector<int>>directions={{0,1}, //east
                                    {1,0}, //south
                                    {0,-1}, //west
                                    {-1,0} //north
                                 };
    int radius=0; //kitna aage bdhna h
    int dir=0;
    result.push_back({rStart,cStart});
    while(result.size()<rows*cols){
            if(dir==0|| dir==2){
                radius++;
            }
            for(int i=0;i<radius;i++){
                rStart+=directions[dir][0];
                cStart+=directions[dir][1];

                if(rStart>=0&& rStart<rows &&cStart>=0&& cStart<cols){
                    result.push_back({rStart,cStart});
                }
            }
            dir=(dir+1)%4;  //ghoomna h

    }
    return result;
}

int main(){
    int row=1;
    int cols=4;
    int rstart=0;
    int cstart=0;
    vector<vector<int>>ans= spiral_matrix(row,cols,rstart,cstart);
    for(auto &ch:ans){
        for(auto &it:ch){
            cout<<it<<" ";
        }
    }
}