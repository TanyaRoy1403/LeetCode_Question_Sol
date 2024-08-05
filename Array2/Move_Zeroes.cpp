#include<iostream>
#include<vector>
using namespace std;
/*Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.*/
vector<int> move_zero(vector<int>&arr){
    //move all non_zero ele at front 
    // to keep tarck of non zero element -->pointer non_zero=0
    int non_zero=0;
    //iterate arr
    for(int i=0;i<arr.size();i++){
        if(arr[i]!=0){
            arr[non_zero]=arr[i];
            non_zero++;
        }
    }
    //rest of the position fill zero
    for(int i=non_zero;i<arr.size();i++){
        arr[i]=0;
    }
    return arr;
}
int main(){
    vector<int>arr={0,1,0,3,12};
    vector<int>ans=move_zero(arr);
    for(auto &it:ans){
        cout<<it<<" ";
    }
}
