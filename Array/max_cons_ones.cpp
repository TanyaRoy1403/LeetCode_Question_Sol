#include<iostream>
#include<vector>
using namespace std;
int count_con_one(vector<int>&arr){
    int n=arr.size();
    int count=0;
    int maxCount=0;
    for(int i=0;i<n;i++){
            if(arr[i]==1){
                count++;
                maxCount=max(maxCount,count);
            }
            else{
                count=0;
            }

    }
    return maxCount;
}
int main(){
    vector<int>arr={1,1,0,1,1,1};
    int n=arr.size();
    cout<<count_con_one(arr);
}
