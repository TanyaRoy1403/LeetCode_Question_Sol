#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

vector<int>maxSub(vector<int>&arr,int k){
    //take min heap -->store element with its index
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>hp;
    
    //insert element 
    int n=arr.size();
    for(int i=0;i<n;i++){
        hp.push({arr[i],i});
        //remove k+1 min element then we left with only max element in the heap
        if(hp.size()>k){
            hp.pop();
        }
    }
    //now exact max element 
    vector<pair<int,int>>ans;
    while(!hp.empty()){
        ans.push_back(hp.top());
        hp.pop();
    }
    //sort then ans with respect to index so that order maintain rhega 
    sort(ans.begin(),ans.end(),[](auto  &a, auto &b){
        return a.second<b.second;
    });
      // Collect result
    vector<int> result;
    for (auto &p : ans)
        result.push_back(p.first);
    return result;
}
int main(){
    vector<int>arr={-1,-2,3,4};
    int k=3;
    vector<int>ans=maxSub(arr,k);
    for(auto &ch:ans){
        cout<<ch<<" ";
    }
    return 0;
}
