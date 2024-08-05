#include<iostream>
#include<vector>
#include<string>
#include<climits>
using namespace std;

//^Longest Sub-Array with Sum K
/*Given an array arr containing n integers and an integer k. Your task is to find the length of the longest 
Sub-Array with the sum of the elements equal to the given value k.*/

int solve(vector<int>arr,int k){
    int n=arr.size();
    int i=0,j=0;
    int sum=0;
    int max_len=0;
    while(j<n){
        long long sum_re=sum+arr[j];
        while(sum_re>k){
            sum_re-=arr[i];
            i++;
        }
        if(sum_re==k){
            max_len=max(max_len,j-i+1);
        }
        
        j++;
        
    }
    return max_len;
}
int main(){
    vector<int>arr={-13,0,6,15,16,2,15,-12,17,-16,0,-3,19,-3,2,-9,-6};
    int k=15;
    cout<<solve(arr,k);
}