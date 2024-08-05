#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
/*Your laptop keyboard is faulty, and whenever you type a character 'i' on it, 
it reverses the string that you have written. Typing other characters works as expected.

You are given a 0-indexed string s, and you type each character of s using your faulty keyboard.

Return the final string that will be present on your laptop screen.Input: s = "poiinter"
Output: "ponter"*/

string final_str(string s){
    string result="";
    for(int i=0;i<s.length();i++){
        if(s[i]!='i'){
            result.push_back(s[i]);
        }else{
            reverse(begin(result),end(result));
        }
    }
    return result;
}
int main(){
    string s="poiinter";
    cout<<final_str(s);
}