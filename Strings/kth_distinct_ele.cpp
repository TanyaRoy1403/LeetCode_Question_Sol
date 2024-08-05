#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;

string solve(vector<string>&arr,int k){

    unordered_set<string>st;
    for(auto &ch:arr){
        if(st.find(ch)!=st.end()){
        st.erase(ch);
        }else{
            st.insert(ch);
        }
    }

    if (k > st.size()) {
        return ""; // or throw an error, depending on your requirements
    }

    // Iterate through the set to find the k-th element
    int count = 0;
    for (const auto& elem : st) {
        if (++count == k) {
            
            return elem;
        }
    }

    return "";
}

string solve2(vector<string>&arr,int k){

    unordered_map<string,int>mp;

        for(auto &ch:arr){
            mp[ch]++;
        }
        for(auto &it:arr){
            if(mp[it]==1){
                k--;
            }
        
          if(k==0){
               return it;
            }
        }
        return "";
}
int main(){
    vector<string>arr={"d","b","c","b","c","a"};
    int k=2;
    cout<<solve(arr,k);
}