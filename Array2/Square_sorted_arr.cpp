#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.
Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]*/


vector<int> solve(vector<int>&arr){
    int n=arr.size();
    vector<int>ans(n);
    // for(int i=0;i<arr.size();i++){
    //     arr[i]=abs(arr[i]*arr[i]);
    //     ans.push_back(arr[i]);
    // }
    // sort(begin(ans),end(ans));
    // return ans;


/*-----------------------------//*Optimal solution-------------------------------------------------------- */
     int s=0;
     int e=n-1;
     int k=n-1;  //^index of final array(ans)
     while(s<=e){
        int left_sq=arr[s]*arr[s];
        int rigth_sq=arr[e]*arr[e];
        if(left_sq>rigth_sq){
            ans[k]=left_sq;   //^ans ke last me biggest ele -->left_sq hog n
            k--;
            s++;
        }else{
            ans[k]=rigth_sq;
            k--;
            e--;
        }
     }
    return ans;
}

int main(){
    vector<int>arr={-4,-1,0,3,10};
    vector<int>ans=solve(arr);
    for(auto &it:ans){
        cout<<it<<" ";
    }
}