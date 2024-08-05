#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.*/

//concept-->3_sum + two_sum(2)+store andd compute

int sum_closest(vector<int>&arr,int target){
    int n=arr.size();
    sort(begin(arr),end(arr));  //O(nlogn)
    int close_sum=10000000;
    for(int k=0;k<=n-3;k++){  //fix element ka loop   O(n)
        int i=k+1;
        int j=n-1;
        while(i<j){  //O(n)
            int sum=arr[k]+arr[i]+arr[j];
            if(abs(target-sum)<abs(target-close_sum)){
                close_sum=sum;   //store and compute
            }else if(target<sum){
                j--;
            }else{
                i++;
            }
        }
    }
    return close_sum;  //overall-->t.c-->O(n square)
}
int main(){
    vector<int>arr={-1,2,1,-4};
    int target=1;
    cout<<sum_closest(arr,target);

}