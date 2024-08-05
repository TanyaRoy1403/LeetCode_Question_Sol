#include<iostream>
#include<string>
#include<vector>
using namespace std;
#include "split_function.cpp"

/*There is a malfunctioning keyboard where some letter keys do not work. All other keys on the keyboard work properly.

Given a string text of words separated by a single space (no leading or trailing spaces) and a string brokenLetters of all distinct letter keys that are broken, 
return the number of words in text you can fully type using this keyboard.*/


int max_word(string text, string brokenLetters){

    vector<bool>arr(26,false);
    for(auto &it:brokenLetters){
        arr[it-'a']=true;
    }
    int count=0;
    for(auto &ch:split(text,' ')){
       bool canType=true;
        for(auto &it:ch){
            if(arr[it-'a']){
                canType=false;
                break;
            }
        }
        if(canType){
            count++;
        }
    }
    return count;
}
int main(){
    string text="hello wolrd";
    string brokenLtters="ad";
    cout<<max_word(text,brokenLtters);
}