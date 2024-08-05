#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
const int MOD =1e9+7;

int solve(vector<int>&arr,int left,int right){
    int n=arr.size();
    // int m=n*(n+1)/2;
    vector<int>ans;
    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=i;j<n;j++){
            sum+=arr[j];
            ans.push_back(sum);
      
        }
    }
    sort(ans.begin(),ans.end());
    int final_sum=0;
    for(int i=left-1;i<right;i++){
        final_sum=(final_sum+ans[i])%MOD;
    }

    return final_sum;
}
int main(){
    vector<int>arr={1,2,3,4};
    int left=1;
    int right=5;
    cout<<solve(arr,left,right);
}