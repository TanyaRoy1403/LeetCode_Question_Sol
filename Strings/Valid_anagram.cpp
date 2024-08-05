#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
/*Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, 
typically using all the original letters exactly once.Input: s = "anagram", t = "nagaram"
Output: true*/

bool val_anangram(string s,string t){
    unordered_map<char,int>mp;
    if(s.length()<t.length()){
        return false;
    }
    for(auto &ch:s){
        mp[ch]++;
    }
    for(auto &it:t){
        mp[it]--;
        if(mp[it]<0){
            return false;
        }
    }
    return true;

}
int main(){
    string s="anagr";
    string t="nagaram";
    cout<<val_anangram(s,t);
}