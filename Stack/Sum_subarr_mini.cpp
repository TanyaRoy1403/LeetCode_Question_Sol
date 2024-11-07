#include<iostream>
#include<vector>
#include<stack>
#include<climits>
using namespace std;

const int MOD = 1e9 + 7;
/*Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. 
Since the answer may be large, return the answer modulo 109 + 7.*/

/*-------------------------------Brute force--O(n*3)-----------------------------------------*/
int solve(vector<int>&arr){
    int n=arr.size();
    int sum=0;
    //generate all subarr
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int min_value=INT_MAX;
            for(int k=i;k<=j;k++){
                if(arr[k]<min_value){
                    min_value=arr[k];
                }
            }
            sum=(sum+min_value)%MOD;
        }
    }

return sum;
    
}
/*-------------------------------Brute force--O(n*2)-----------------------------------------*/
int solve2(vector<int>&arr){
    int n=arr.size();
    long long int sum=0;
    //generate all subarr
    for(int i=0;i<n;i++){
        //maan lete h av jo h wohi min h
        int min_val=arr[i];
        for(int j=i;j<n;j++){
            if(arr[j]<min_val){
                min_val=arr[j];
            }
            sum=(sum+min_val)%MOD;
        }
    }

return sum;
    
}
int main(){
    vector<int>arr={11,81,94,43,3};
    cout<<solve2(arr);
}