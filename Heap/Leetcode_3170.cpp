#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*You are given a string s. It may contain any number of '*' characters. Your task is to remove all '*' characters.

While there is a '*', do the following operation:

Delete the leftmost '*' and the smallest non-'*' character to its left. If there are several smallest characters, you can delete any of them.
Return the lexicographically smallest resulting string after removing all '*' characters.*/
struct comp{
    bool operator()(pair<char,int>&p1, pair<char,int>&p2){
        if(p1.first==p2.first){
            return p1.second<p2.second;
        }
        return p1.first>p2.first;
    }
};

string GetSmallestSString(string s){
    priority_queue<pair<char,int>, vector<pair<char,int>>, comp>pq;
    for(int i=0;i<s.length();i++){
        if(s[i]!='*'){
            pq.push({s[i],i});
        }else{
            int idx=pq.top().second;
            pq.pop();
            s[idx]='*';
        }
    }
        string result="";
        for(int i=0;i<s.length();i++){
            if(s[i]!='*'){
                result.push_back(s[i]);
            }
        }
return result;
    
}
int main(){
    string s="ead*";
    string ans=GetSmallestSString(s);
    cout<<ans;
}