#include<iostream>
#include<vector>
using namespace std;

/*You are given a 0-indexed array nums of n integers, and an integer k.

The k-radius average for a subarray of nums centered at some index i with the radius k is the average of all elements in nums between the indices i - k and i + k (inclusive). 
If there are less than k elements before or after the index i, then the k-radius average is -1.

Build and return an array avgs of length n where avgs[i] is the k-radius average for the subarray centered at index i.

The average of x elements is the sum of the x elements divided by x, using integer division. The integer division truncates toward zero, 
which means losing its fractional part.*/

vector<int> solve(vector<int>&arr,int k){
    int left_indx=0;  //lef pointer of window
    int right_idx=2*k;  //right pointer of window

    int i=k;
    

}