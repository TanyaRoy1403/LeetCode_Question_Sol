#include<iostream>
#include<vector>
using namespace std;
/*Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is 
the smallest in lexicographical order
 among all possible results.Input: s = "bcabc"  Output: "abc"*/
string removeDuplicateLetters(string s) {
        int n = s.length();
        string result;
        
        vector<bool>visited(26, false); //O(1) space
        vector<int> lastIndex(26); //O(1) space
        
        for(int i = 0; i < n; i++) {
            char ch = s[i];
            
            lastIndex[ch-'a'] = i;  //^ store last index of each char
        }
        
        
        for(int i = 0; i < n; i++) {
            
            int idx = s[i] - 'a';
            
            if (visited[idx] == true) continue;
            
            while(result.length() > 0 && s[i] < result.back() && lastIndex[result.back() - 'a'] > i) {
            visited[result.back() - 'a'] = false;
                result.pop_back();
            }
            
            result.push_back(s[i]);
        visited[idx] = true;
            
        }
        
        return result;
    }
int main(){
    string s="bcabc";
    cout<<removeDuplicateLetters(s);
}