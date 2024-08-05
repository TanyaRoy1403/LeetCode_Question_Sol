#include<iostream>
#include<string>
#include<vector>
using namespace std;

// int solve(string word,string needle){
//     int idx=-1;
//     string result="";
//     if(needle.length()>word.length()){
//             return -1;
//         }
//     for(int i=0;i<word.length();i++){
//         char ch=needle[0];
//         if(word[i]==ch){
//             result+=word.substr(i,needle.length());
//             if(needle==result){
//                 idx=i;
//                 result.clear();
//             }
//         }
//     }
//     return idx;
// }

int solve(string haystack, string needle) {
    if (needle.length() > haystack.length()) {
        return -1;
    }

    for (int i = 0; i <= haystack.length() - needle.length(); i++) {
        if (haystack.substr(i, needle.length()) == needle) {
            return i;
        }
    }

    return -1;
}


int main(){
    string word="sadbutsad";
    string needle="sad";
    cout<<solve(word,needle);
}