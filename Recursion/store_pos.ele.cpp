#include<iostream>
#include<vector>
using namespace std;
void store_pos(int arr[],int n,int ele,int i,vector<int>&ans){
    if(i==n){
        return ;
    }
    if(arr[i]==ele){
        ans.push_back(i);
    }
    store_pos(arr,n,ele,i+1,ans);
}
int main(){
    int arr[]={5,5,6,5,6};
    vector<int>v;
    store_pos(arr,5,6,0,v);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}
