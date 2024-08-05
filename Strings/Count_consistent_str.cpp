#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;
/*You are given a string allowed consisting of distinct characters and an array of strings words. A string is consistent if 
all characters in the string(words) appear in the string allowed.

Return the number of consistent strings in the array words.Input: allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
Output: 2
Explanation: Strings "aaab" and "baa" are consistent since they only contain characters 'a' and 'b'.*/

int consit_str(string allowed,vector<string>&words){
         //*using count array

        // vector<bool>arr(26,false);
        // for(auto &it:allowed){
        //     arr[it-'a']=true; //^index of char
        // }


        //*using map
        unordered_map<char,bool>mp;
        for(auto &it:allowed){
            mp[it]=true;
        }
        int count=0;
        for(auto &ch:words){
            bool isFind=true;
            for(auto &x:ch){
                if(mp.find(x)==mp.end()){  //!for using map
                    isFind=false;
                    break;
                }
/*------------------------------------//!using count arr------------------------------------------------*/
                // if(!arr[it-'a']){
                //     isFind=false;
                //     break;
                // }
/*---------------------------------------------------------------------------------------------------------*/
            }
            if(isFind){
                count++;
            }
        }
        return count;
}
int main(){
    vector<string>words={"a","b","c","ab","ac","bc","abc"};
    string allowed="abc";
    cout<<consit_str(allowed,words);

}