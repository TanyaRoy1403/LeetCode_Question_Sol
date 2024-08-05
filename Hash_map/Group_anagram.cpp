#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
/*Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
typically using all the original letters exactly once.  Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]*/

vector<vector<string>> groupAnagrams(vector<string>& strs){
    unordered_map<string,vector<string>>mp;  //^key(string):value:{isme iss key ka sara anagram hoga}
    vector<vector<string>>ans;
    for(int i=0;i<strs.size();i++){
            string temp=strs[i];
            sort(begin(temp),end(temp));
            mp[temp].push_back(strs[i]);
        }
        for(auto &it:mp){
            ans.push_back(it.second);
        }
        return ans;

}
int main(){
    vector<string>strs={"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>>ans=groupAnagrams(strs);
    for(auto &it:ans){
        for(auto &ch:it){
            cout<<ch<<" ";
        }
        cout<<endl;
    }
}