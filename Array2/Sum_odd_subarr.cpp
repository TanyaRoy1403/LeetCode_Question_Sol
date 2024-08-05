#include<iostream>
#include<vector>
using namespace std;

/*Given an array of positive integers arr, return the sum of all possible odd-length subarrays of arr.Input: arr = [10,11,12]
Output: 66*/


int solve(vector<int>&arr){
    int n=arr.size();
    int sum=0;
/*----------------------------------//!Brute force--------------------------------------------------------------------------------------*/
    // for(int i=0;i<n;i++){
    //     for(int j=i;j<n;j+=2){  //*kyu ki hme sirf odd len chaiye
            
    //         for(int k=i;k<=j;k++){  //*subarr dega
    //             sum+=arr[k];
    //         }
    //     }
    // }
    // return sum;
/*--//^Time complexity:O(n cube)---
----//*space complexity:O(1)------------------------------------------------------------------------------------------------------------*/


/*-------------------------- optimal solution-----------------------------------------------------------------------------*/
//~ any i of arr has i+1 choices of odd len subarr on it left and n-i on right side of it, so total odd len subarr is ((i+1)*(n-i)+1)/2-->len_odd
//~ and their sum is -->len_odd*arr[i]
  for(int i=0;i<n;i++){
    sum+=(((i+1)*(n-i)+1)/2)*arr[i];
  }
    return sum;
}

int main(){
    vector<int>arr={1,4,2,5,3};
    cout<<solve(arr);
}