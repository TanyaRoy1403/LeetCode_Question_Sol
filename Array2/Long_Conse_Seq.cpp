#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

You must write an algorithm that runs in O(n) time.*/

bool linear_search(vector<int>&arr,int target){
    for(int i=0;i<arr.size();i++){
        if(arr[i]==target){
            return true;
        }
    }
    return false;
}

int solve(vector<int>&arr){
    //brute force
    int n=arr.size();
    int max_len=0;
    // int curr_len=1;
    
    for(int i=0;i<n;i++){
        int curr_len=1;
        int nex_ele=arr[i]+1;
        while(linear_search(arr,nex_ele)){
                curr_len++;
                nex_ele++;
        }
        max_len=max(max_len,curr_len);
    }
    return max_len;
/*Time complexity:O(n cube)---
---Space complexity:O(1)------------------------------------------------------------------------------------------------------*/
}
/*--------------------------------------------Optimal solution----------------------------------------------------------*/
int solve2(vector<int>&arr){
    int n=arr.size();
    if(n==0){
        return 0;
    }
    sort(begin(arr),end(arr));
    int prev=arr[0];
    int curr=1;
    int max_len=0;
    int curr_len=1;
    for(int i=1;i<arr.size();i++){
        if(prev==arr[i]){ //dupicates
            continue;
        }
        if(arr[i]==prev+1){ //shi seq mil rha h
            curr_len++;
            prev=arr[i];
        }else{
            curr_len=1;  //koi or ele mil (arr[i]!=prev+1) isliye rest kr diiya
            prev=arr[i];
        }
        max_len=max(max_len,curr_len);
    }
    return max_len;
}
int main(){
    vector<int>arr={0,3,7,2,5,8,4,6,0,1};
    cout<<solve(arr);
    cout<<endl;
    cout<<solve2(arr);
    return 0;

}