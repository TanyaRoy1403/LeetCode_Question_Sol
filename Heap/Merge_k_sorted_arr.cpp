#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int>mergeK(vector<vector<int>>arr,int k){

    //pair(value,row,col)
    // pair<int,pair<int,int>>pr;
    //to store first column and push into min heap we have to store it in temp arr for better time complexity
    vector<pair<int,pair<int,int>>>temp;
    for(int i=0;i<k;i++){
        temp.push_back(make_pair(arr[i][0],make_pair(i,0)));
    }
    //min heap
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq(temp.begin(),temp.end());
    //final vector
    vector<int>ans;
    pair<int,pair<int,int>>Ele;
    int i,j;
    while(!pq.empty()){
        Ele=pq.top();
        pq.pop();
        ans.push_back(Ele.first); //value
        i=Ele.second.first;
        j=Ele.second.second;
        if(j+1<k){
            pq.push(make_pair(arr[i][j+1],make_pair(i,j+1)));
        }
    }
    return ans;
}
int main(){
    vector<vector<int>>arr={{1,2,3},{4,5,6},{7,8,9}};
    int k=3;
    vector<int>ans=mergeK(arr,k);
    for(auto x:ans){
        cout<<x<<" ";
    }
    return 0;
}