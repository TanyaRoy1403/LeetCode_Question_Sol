#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<map>
#include<algorithm>
using namespace std;
class Solution{
public:
    static bool custom_com(pair<int,string>&a,pair<int,string>&b){
        return a.first>b.first;
    }
vector<string> sortPeople(vector<string>& names, vector<int>& heights){
    // map<int,string,greater<int>>mp; 
    //     for(int i=0;i<names.size();i++){
    //         mp[heights[i]]=names[i];
    //     }
    //     vector<string>ans;
    //     for(auto &it:mp){
    //         ans.push_back(it.second);
    //     }
    //     return ans;

    //^method 2
    vector<pair<int,string>>p;
    for(int i=0;i<heights.size();i++){
        p.push_back({heights[i],names[i]});
    }
    //^sort-->to sort pair we usin sort stl we need custom comprator we compare two pairs

    // sort(begin(p),end(p),custom_com);  //*inseated of using diff fun we can use lamda fun-->[](pair<int,string>a,pair<int,string>b){return a.first>b.first;}
    sort(begin(p), end(p), [](const pair<int, string>& a, const pair<int, string>& b) {return a.first > b.first;} );
    vector<string>result;
    for(auto &ch:p){
        result.push_back(ch.second);
    }
    return result;
}
};
int main(){
    vector<string>names={"Mary","John","Emma"};
    vector<int>height={180,165,170};
    // vector<string>ans=sortPeople(names,height);
    Solution obj;
    vector<string>ans=obj.sortPeople(names,height);
    for(auto &ch:ans){
        cout<<ch<<" ";
    }

}
