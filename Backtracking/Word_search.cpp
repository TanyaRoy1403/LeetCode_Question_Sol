#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. 
The same letter cell may not be used more than once.*/



int len,row,col,idx;
vector<vector<int>>direction={{1,0},{-1,0},{0,1},{0,-1}};
bool find(vector<vector<char>>&arr,int i,int j,string &word,int idx){
    //base case

    if(idx==len){
        return true;
    }
    if(i<0||j<0||i>=row||j>=col||arr[i][j]=='V'||arr[i][j]!=word[idx]){
        return false;
    }
    //^aisa nhi hua to baaki ka letters find krege
    char temp=arr[i][j];  //^current char to store kr liye
    arr[i][j]='V';  //^current char ko visited mark kr diye

    //*backtracking lga rhe h

    for(auto &it:direction){
        int new_i=i+it[0];   //*backtrack krne ke liye kon sa direction me jana h uska nya coordinate
        int new_j=j+it[1];
        if(find(arr,new_i,new_j,word,idx+1)) //*recursivly backtrack kiye
        return true;
    }
    arr[i][j]=temp;  //^fir jaise  backtracking ktm ho jayeg waise  visited mark char ko unvisited kr deyeg


return false;


}

bool word_serch(vector<vector<char>>&arr,string word){
    row=arr.size();
    col=arr[0].size();
    idx=0;
    len=word.length();
    //*traverse through the matrix to search for first letter of word
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(arr[i][j]==word[0] && find(arr,i,j,word,0)){   //^ find-->baaki bache letters ko dhoondhega 
                    return true;
            }
        }
    }
    return false;
}

int main(){
        vector<vector<char>> arr = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    string word= "SEE";
    bool result=word_serch(arr,word);
    if(result){
        cout<<"found"<<endl;
    }else{
        cout<<"not found";
    }

}