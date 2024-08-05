#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*You are given a 0-indexed array of strings words and a character x.

Return an array of indices representing the words that contain the character x.

Note that the returned array may be in any order.Input: words = ["leet","code"], x = "e"  Output: [0,1]*/

vector<int> solve(vector<string>& words, char x) {
        vector<int>ans;
        for(int i=0;i<words.size();i++){
            for(auto &ch:words[i]){
                if(ch==x){
                    ans.push_back(i);
                    break;
                }
            }
        }
    return ans;
        
}
int main(){
    vector<string>word={"leet","code"};
    char x='e';
    vector<int>ans=solve(word,x);
    for(auto &it:ans){
        cout<<it;
    }
}