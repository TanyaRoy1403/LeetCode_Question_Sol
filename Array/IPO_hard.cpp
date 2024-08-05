#include<bits/stdc++.h>
using namespace std;
int project_buy(int k,int w,vector<int>&profits,vector<int>&capitals){
    int n=profits.size();
    vector<pair<int,int>>vec(n);
    for(int i=0;i<n;i++){
        vec[i]={capitals[i],profits[i]};
    }
    sort(begin(vec),end(vec));
    int i=0;
    priority_queue<int>pq;
    while(k--){
        while(i<n&&vec[i].first<=w){
            pq.push(vec[i].second);
            i++;
        }
        if(pq.empty()){
            break;
        }
        w+=pq.top();
        pq.pop();
    }
    return w;
}
int main(){
    vector<int>profits={1,2,3};
    vector<int>capitals={0,1,1};
    int k=2;
    int w=0;
    cout<<project_buy(k,w,profits,capitals);
}
