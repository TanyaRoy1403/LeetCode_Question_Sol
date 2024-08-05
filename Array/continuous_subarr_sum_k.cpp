#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
bool cont_sub_mul_k(vector<int>&arr,int k){
    int n=arr.size();
    unordered_map<int,int>mp; ///store remainder of c.s when div k and value -->index of ele
    mp[0]=-1;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
        if(mp.find(sum%k)!=mp.end()){
            if(mp[sum%k]<i){
                return true;
            }
        }
        else{
            mp[sum%k]=i+1;
        }
    }
    return false;

}
bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> cumulativeSum(n + 1, 0);


        for (int i = 1; i <= n; i++) {
            cumulativeSum[i] = cumulativeSum[i - 1] + nums[i - 1];
        }
        for (int start = 0; start < n - 1; start++) {
            for (int end = start; end < n; end++) {
                int subarraySum = cumulativeSum[end ] ;
                if (subarraySum == 0 && k == 0) {
                    return true;
                }
                if (k != 0 && subarraySum % k == 0) {
                    return true;
                }
            }
        }

        return false;
    }
///brute force
bool cont_subarr(vector<int>&arr ,int k){
    int n=arr.size();
    int sum=0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            for(int x=i;x<=j;x++){
                sum+=arr[x];
            }
            if (sum == 0 && k == 0) { // Handling special case where k is 0
                    return true;
                }
            if (k != 0 && sum % k == 0) {
                    return true;
            }
       }
    }
    return false;
}
int main(){
    vector<int>arr={23,2,6,4,7};
    int n=arr.size();
    bool result=checkSubarraySum(arr,13);
    if(result){
        cout<<"True,subarr found:"<<endl;
    }
    else{
        cout<<"False subarr not found:"<<endl;
    }

}

