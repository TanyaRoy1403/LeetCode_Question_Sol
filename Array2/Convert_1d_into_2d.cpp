#include<iostream>
#include<vector>
using namespace std;
// 1d-->index of ele-->2d--> row_no=index/no_of_col and col_no=index%no_of_col

vector<vector<int>> Convert(vector<int>&arr,int row,int col){
    int n=arr.size();
    vector<vector<int>>ans(row,vector<int>(col));
    if(n!=row*col){        //row*col-->total no of element goining to be in 2d array
        return {};          //return empty ans
    }
    for(int i=0;i<n;i++){
        int row_no=i/col;
        int col_no=i%col;
        ans[row_no][col_no]=arr[i];
    }
    return ans;

}
int main(){
    vector<int>arr={1,2,3,4};
    int row=2;
    int col=3;
    vector<vector<int>>result=Convert(arr,row,col);
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<result[i][j];
        }
    cout<<endl;
    }
}