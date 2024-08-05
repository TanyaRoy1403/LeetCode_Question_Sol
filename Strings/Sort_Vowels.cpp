// #include<iostream>
// #include<string>
// #include<vector>
// #include<unordered_map>
// using namespace std;
/*Given a 0-indexed string s, permute s to get a new string t such that:

All consonants remain in their original places. More formally, if there is an index i with 0 <= i < s.length such that s[i] is a consonant, 
then t[i] = s[i].
The vowels must be sorted in the nondecreasing order of their ASCII values. More formally, for pairs of indices i, j with 0 <= i < j < s.length 
such that s[i] and s[j] are vowels, then t[i] must not have a higher ASCII value than t[j].
Return the resulting string.*/

// bool isVowels(char ch){
//     ch=tolower(ch);
//     return(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u');
// }
// string sort_vowels(string s){
//     vector<int >count_arr(26);
//     for(auto &ch:s){
//         if(isVowels(ch)){
//             int idx=tolower(ch)-'a';
//             count_arr[idx]++;
//         }
//     }
//     string temp="aeiou";
//     int j=0;
//     for(int i=0;i<s.length();i++){
//         if(isVowels(s[i])){
//             while(count_arr[temp[j]-'a']==0){
//                 j++;
//             }
//             s[i]=temp[j];
//             count_arr[temp[j]-'a']--;
//         }
//     }
//     return s;

// }

#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

 bool isVowel(char ch) {
        ch = tolower(ch);
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
    
    string sortVowels(string s) {
        unordered_map<char, int> mp;
        
        for(char &ch : s) {
            if(isVowel(ch)) {
                mp[ch]++;
            }
        }
        
        string temp   = "AEIOUaeiou";
        
        int j = 0; //pointing to temp (current vowel)
        
        for(int i = 0; i<s.length(); i++) {
            
            if(isVowel(s[i])) {
                while(mp[temp[j]] == 0) {
                    j++;
                }
                
                s[i] = temp[j];
                mp[temp[j]]--;
            }
            
        }
        
        return s;
        
    }
int main(){
    string s= "lEetcOde";
    cout<<sortVowels(s);
}