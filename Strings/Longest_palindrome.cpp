#include<iostream>
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;
/*Given a string s which consists of lowercase or uppercase letters, return the length of the longest 
palindrome
 that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome.Input: s = "abccccdd"
Output: 7*/


string toLower(string &s){
    string result="";
    for(const char &ch:s){
        if(ch>='A'&&ch<='Z'){
            result+=ch-'A'+'a';
        }else{
            result+=ch;
        }
    }
    return result;
}
/*----------------------------------//^Greedy with hashMap-----------------------------------------------------------*/
int longest_pali(string s){
    s=toLower(s);
    unordered_map<char,int>freqMap;
    for(auto &ch:s){
        freqMap[ch]++;
    }
    int count=0;
    bool Oddflag=false;
    for(auto &it:freqMap){
        int freq=it.second;
        if(freq%2!=0){  //^agr freq odd h mtlb sare ka pair nhi hua h ek bach hi jayega to usko center me daal dena h
            count+=freq-1;
            Oddflag=true;

        }else{
            count+=freq;
        }
    }
    if(Oddflag){   //^iska mtlb ek na ek odd occurence wala char h to usko center me kr deyge taki wohi v count ho or count ko bda de
        count+=1;
    }
    return count;
/*---TimeCompplexity:O(n)-----
-----------SpaceComplexity:O(n)----------------------------------------------------------------------------------------------------*/

/*---------------------------------//*Greedy with set----------------------------------------------------------------------------*/
    unordered_set<char> characterSet;
        int res = 0;

        // Loop over characters in the string
        for (char c : s) {
            if (characterSet.find(c) != characterSet.end()) {  //~agr char mil gya to usko erase kr do or count ko 2 bda do kyu milne ka mtlb-->pair me exist krta h
                characterSet.erase(c);
                // add the two occurrences to our palindrome
                res += 2;
            } else {
                // add the character to the set
                characterSet.insert(c);  //~agr nhi mila h to sidha insert kr do uss char ko
            }
        }

     
        if (!characterSet.empty()) {  //! set empty nhi hua h mtlb sara char ka pairing nhi ho paya h kyu kuch odd count wale char v h to usko center me use kr lo or count ko++
            res++;
        }

        return res;
}

int main(){
    string s="abccccdd";
    cout<<longest_pali(s);
}


