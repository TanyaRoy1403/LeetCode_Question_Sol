#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
void print_subarr(vector<int>&arr){
    int n=arr.size();
    for(int sp=0;sp<n;sp++){
        for(int ep=sp;ep<n;ep++){
            for(int i=sp;i<=ep;i++){

           cout<<arr[i]<<" ";
            }
            cout<<endl;


        }
    }
}
///brute force o(n^2)
int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int sum = 0;
            for(int j = i; j < n; j++) {
                sum += nums[j];
                if(sum == k) count++;
            }
        }
        return count;
    }

///optimal o(n)
int count_sub(vector<int>&arr,int k){
    int n=arr.size();
    int PrefixSum=0;
    int result=0;
    unordered_map<int,int>mp;    ///in map we insert the value of prefixsum
    mp.insert({0,1});
    for(int i=0;i<n;i++){
        PrefixSum+=arr[i];
    if(mp.find(PrefixSum-k)!=mp.end()){
        result+=mp[PrefixSum-k];

    }
    mp[PrefixSum]++;
    }
    return result;
}

int main(){
    vector<int>arr={1,2,3};
//    print_subarr(arr);

    cout<<count_sub(arr,3);
}
