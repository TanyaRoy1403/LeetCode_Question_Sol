#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int solve(vector<int>&arr){
    int n=arr.size();
    int max_len=*max_element(arr.begin(),arr.end());  //Note--> count array will not handle negative elements as negative indexing not possible
    vector<int>ans(max_len+1,0);
    for(auto &it:arr){
        ans[it]++;
    }
    for(int i=0;i<=max_len;i++){
        if(ans[i]>n/2){
            return i;
        }
    }
    return -1;
}
int main(){
    vector<int>arr={-1,1,1,1,2,1};
    int n=arr.size();
    cout<<solve(arr);
}