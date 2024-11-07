#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<queue>
using namespace std;

/*Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.*/

/*------------------------------------------Brute force----------------------------------------------*/
vector<int> solve(vector<int>&arr,int k){
    unordered_map<int,int>mp;
    vector<int>ans;
    for(auto &it:arr){
        mp[it]++;
    }
    for(auto& ch:mp){
        if(ch.second>=k){
            ans.push_back(ch.first);
        }
    }
    sort(begin(ans),end(ans));
    return ans;
}
/*------------------------optimal solution(max heap)---------------------------------------------------*/

vector<int> k_most_frq(vector<int>&arr,int k){
    unordered_map<int,int>mp;
    vector<int>ans;  //auxilary space no extra space
    for(auto &it:arr){
        mp[it]++;
    }
    //add freq and ele into max heap-->at top it will contain ele with max frq
    priority_queue<pair<int,int>>frqHeap;
    for(auto &it:mp){
        frqHeap.push({it.second, it.first});
    }
     // Extract the top k elements with the highest frequency
    for(int i=0;i<k;i++){
        ans.push_back(frqHeap.top().second); //kyu hmne heap me (frq:ele) ka pir bnaya tha
        frqHeap.pop();
    }
    return ans;
}
int main(){
    vector<int>arr={1,1,1,2,2,3};
    int k=2;
    vector<int>ans=solve(arr,k);
    for(auto &ch:ans){
        cout<<ch<<" ";
    }
}