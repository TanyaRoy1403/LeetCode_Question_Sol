#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
bool canEat(vector<int>&arr,int hr,int k){
    long long int total_hours=0;
    for(int i=0;i<arr.size();i++){
        total_hours+=ceil(arr[i]/(double)k);
    }
    if(total_hours<=hr) return true;
    return false;
}
int solve(vector<int>&arr,int hr){
    int s=1;
    int e=*max_element(arr.begin(),arr.end());
    int ans=0;
    while(s<=e){
        int mid=s+(e-s)/2;
        int k=mid;
        if(canEat(arr,hr,k)){
            ans=k;
            e=mid-1;
        }else{
            s=mid+1;
        }
    }
    return ans;
}
int main(){
    vector<int>arr={3,6,7,11};
    int hr=8;
    cout<<solve(arr,hr);
}