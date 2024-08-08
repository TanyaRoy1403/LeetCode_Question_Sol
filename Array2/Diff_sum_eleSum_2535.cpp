#include<iostream>
#include<vector>
using namespace std;
/*You are given a positive integer array nums.

The element sum is the sum of all the elements in nums.
The digit sum is the sum of all the digits (not necessarily distinct) that appear in nums.
Return the absolute difference between the element sum and digit sum of nums.

Note that the absolute difference between two integers x and y is defined as |x - y|.*/

int solve(vector<int>&arr){
    int all_sum=0;
    int digit_sum=0;
    for(int i=0;i<arr.size();i++){
        all_sum+=arr[i];

        int curr=arr[i];
        while(curr>0){
            int digit=curr%10;
            digit_sum+=digit;
            curr/=10;
        }
    }
    return abs(all_sum-digit_sum);
    
}
int main(){
    vector<int>arr={1,15,6,3};
    cout<<solve(arr);
}