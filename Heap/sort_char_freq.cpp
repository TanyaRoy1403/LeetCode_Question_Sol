#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;

string solve(string s){
    map<char,int>mp;
    for(auto& ch:s){
        mp[ch]++;
    }
    vector<pair<int,char>>v;
    for(auto& ele:mp){
        v.push_back({ele.second,ele.first});
    }
    sort(v.begin(),v.end(),greater<pair<int,char>>());
    string ans="";
    for(auto& ele:v){
        for(int i=0;i<ele.first;i++){
            ans+=ele.second;
        }
    }
    return ans;
}
//using heap
string solve2(string s){
    priority_queue<pair<int,char>>pq;
    map<char,int>mp;
    for(auto& ch:s){
        mp[ch]++;
    }
    for(auto& ele:mp){
        pq.push({ele.second,ele.first});
    }
    string ans="";
    while(!pq.empty()){
        auto ele=pq.top();
        pq.pop();
        for(int i=0;i<ele.first;i++){
            ans+=ele.second;
        }
    }
    return ans;
}
int main(){
    string s="cccaaa";
    cout<<solve(s);
    return 0;

}