#include<iostream>
#include<vector>
using namespace std;

/*You are given two m x n binary matrices grid1 and grid2 containing only 0's (representing water) and 1's (representing land). 
An island is a group of 1's connected 4-directionally (horizontal or vertical). Any cells outside of the grid are considered water cells.

An island in grid2 is considered a sub-island if there is an island in grid1 that contains all the cells that make up this island in grid2.

Return the number of islands in grid2 that are considered sub-islands.*/

bool DFS(vector<vector<int>>& grid1, vector<vector<int>>& grid2,int x,int y){
    if(x<0||x>=grid1.size()||y<0||y>=grid1[0].size()){
        return true;
    }
    if(grid2[x][y]!=1){ //land mil gya
        return true;
    }
    grid2[x][y]=-1; //mark visited

    //ab grid1 me grid2 jaisa hi land dhooondna h
    bool result=(grid1[x][y]==1);//aghr land mil gya ab charo direction me search krgenge land ko
    result=result& DFS(grid1,grid2,x+1,y);
    result=result&DFS(grid1,grid2,x-1,y);
    result=result&DFS(grid1,grid2,x,y+1);
    result=result&DFS(grid1,grid2,x,y-1);
    return result;

}

int solve(vector<vector<int>>& grid1, vector<vector<int>>& grid2){
    int m=grid2.size();
    int n=grid2[0].size();
    int count=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid2[i][j]==1&&DFS(grid1,grid2,i,j)){
                count++;
            }
        }
    }
    return count;
}
int main(){
    vector<vector<int>>grid1={{1,1,1,0,0},{0,1,1,1,1},{0,0,0,0,0},{1,0,0,0,0},{1,1,0,1,1}};
    vector<vector<int>>grid2={{1,1,1,0,0},{0,0,1,1,1},{0,1,0,0,0},{1,0,1,1,0},{0,1,0,1,0}};

    cout<<solve(grid1,grid2);
}