#include<iostream>
#include<vector>
using namespace std;

vector<int> merge_arr(vector<int>&arr1,vector<int>&arr2,vector<int>&result){
    int n=arr1.size();
    int m=arr2.size();
    int i=0;
    int j=0;
    int k=0;
    while(i<n&&j<m){
        if(arr1[i]<arr2[j]){
            result.push_back(arr1[i]);
            i++;
        }else{
            result.push_back(arr2[j]);
            j++;
        }
    }
    while(i<n){
        result.push_back(arr1[i]);
        i++;
    }
    while(j<m){
        result.push_back(arr2[j]);
        j++;
    }
}
int main(){
    vector<int>arr1={20,40,60,80,90,100};
    vector<int>arr2={10,30,50,70};
    vector<int>result;
    merge_arr(arr1,arr2,result);
    for(auto &it:result){
        cout<<it<<" ";
    }
}