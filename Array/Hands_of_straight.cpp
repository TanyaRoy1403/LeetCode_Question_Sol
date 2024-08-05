#include<bits/stdc++.h>
using namespace std;
bool group_div(vector<int>&arr,int groupSize){
    int n=arr.size();
    map<int,int>mp;
    for(auto &it:arr){
        mp[it]++;
    }
    if(n%groupSize!=0){
        return false;
    }
    while(!mp.empty()){
        int cur=mp.begin()->first;
        for(int i=0;i<groupSize;i++){
            if(mp[cur+i]==0){
                return false;
            }
            mp[cur+i]--;
            if(mp[cur+i]<1){
                mp.erase(cur+i);
            }
        }
    }
    return true;
}
int main(){
    vector<int>arr={1,2,3,4,5};
    int groupSize=4;
    bool result=group_div(arr,groupSize);
    if(result){
        cout<<"True"<<endl;
    }
    else{
        cout<<"False"<<endl;
    }
}
