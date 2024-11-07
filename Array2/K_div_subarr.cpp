// #include<iostream>
// #include<vector>
// #include<unordered_set>
// #include<string>
#include<bits/stdc++.h>
using namespace std;
/*Given an integer array nums and two integers k and p, return the number of distinct subarrays, 
which have at most k elements that are divisible by p.

Two arrays nums1 and nums2 are said to be distinct if:

They are of different lengths, or
There exists at least one index i where nums1[i] != nums2[i].
*/

int solve(vector<int>&arr,int k ,int p){
    unordered_set<string>st;
    for(int i=0;i<arr.size();i++){
        int count_k=0;
        string result="";
        for(int j=i;j<arr.size();j++){
             if(arr[j]%p==0){
                count_k++;
             }
             if(count_k>k){
                break;
             }
            result+= to_string(arr[j])+",";
            st.insert(result);
        }
    }
    return st.size();
}
int main(){
    vector<int>arr={1,2,3,4};
    int k=4;
    int p=1;
    cout<<solve(arr,k,p);
}