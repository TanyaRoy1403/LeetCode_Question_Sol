#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
/*Given a 0-indexed string word and a character ch, reverse the segment of word that starts at index 0 and ends at the index of the first occurrence of ch (inclusive). If the character ch does not exist in word, do nothing.

For example, if word = "abcdefd" and ch = "d", then you should reverse the segment that starts at 0 and ends at 3 (inclusive). The resulting string will be "dcbaefd".
Return the resulting string. Input: word = "abcdefd", ch = "d"
Output: "dcbaefd"*/

string solve(string word,char ch){
    int idx_ch=word.find(ch);
    if(word.find(ch)==0){
        return word;
    }
    for(int i=0;i<=idx_ch/2;i++){
        swap(word[i],word[idx_ch-i]);

    }
    return word;
}
int main(){
    string word="abcd";
    char ch='z';
    cout<<solve(word,ch);
}