/*Given an array of integers nums and a number k, write a function that returns true 
if given array can be divided into pairs such that sum of every pair is divisible by k.nums = [9, 5, 7, 3], k = 6*/
#include<iostream>
#include<vector>
using namespace std;
//Brute force
bool find_pair(vector<int>&nums,int k){
    int n=nums.size();
    vector<bool>used(n,false);
    if(n%2==1){
        return false;
    }
    for(int i=0;i<n-1;i++){
        if(used[i]==true) continue;
        bool foundpair=false;
        for(int j=i+1;j<n;j++){
            if(used[j]==true) continue;
            if(!used[j]&&(nums[i]+nums[j])%k==0){
                used[i]=true;
                used[j]=true;
                foundpair=true;
                break;
            }
        }
        if(!foundpair){
            return false;
        }
    }
    return true;
 
}
//optimal sol

int main(){
   vector<int>nums={4,4,4};
   int n=nums.size();
   int k=3;
   bool result=find_pair(nums,k);
   if(result){
    cout<<"Find"<<endl;
   }
   else{
    cout<<"NOT FIND"<<endl;
   }
   return 0;
}