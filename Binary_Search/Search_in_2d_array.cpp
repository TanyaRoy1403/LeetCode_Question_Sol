#include<iostream>
#include<vector>
using namespace std;
bool search(vector<vector<int>>&matrix,int target){
    int nrow=matrix.size();
    int ncol=matrix[0].size();
    int n=nrow*ncol;
    int s=0;
    int e=n-1;
    while(s<=e){
        int mid=s+(e-s)/2;
        int rowInx=mid/ncol;
        int colInx=mid%ncol;
        if(target==matrix[rowInx][colInx]){
            return true;
        }else if(target>matrix[rowInx][colInx]){
            s=mid+1;
        }else{
            e=mid-1;
        }
    }
    return false;

}
int main(){
    vector<vector<int>>arr={{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target=76;
    cout<<search(arr,target);
}