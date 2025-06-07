#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
#include<algorithm>
using namespace std;

vector<int> mostfre(vector<int>arr,int k){
    //frequency pta kro
    unordered_map<int,int>mp;
    for(auto &i :arr){
        mp[i]++;
    }
    priority_queue<pair<int,int>>hp;
    for(auto& ch:mp){
        hp.push({ch.second,ch.first});
    }
    vector<int>ans;
    for(int i=0;i<k;i++){
        ans.push_back(hp.top().second);
        hp.pop();
    }
    return ans;  
}
int main(){
    vector<int>arr={1,1,1,2,2,3};
    int k=2;
    vector<int>ans=mostfre(arr,k);
    for(auto& i:ans){
        
        cout<<i<<" ";
    }
}