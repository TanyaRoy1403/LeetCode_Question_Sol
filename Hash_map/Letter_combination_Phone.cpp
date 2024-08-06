#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
using namespace std;

//backtracking + recursion

/*Given a string containing digits from 2-9 inclusive, return all possible letter combinations that 
the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.*/

void solve(string digit,string output,int i,vector<string>&ans,string mapping[]){
        ///base case
    if(i>=digit.length()){
            ans.push_back(output);
            return ;
    }
    int number=digit[i]-'0';
    string value=mapping[number];
    for(int j=0;j<value.length();j++){
            output.push_back(value[j]);
            solve(digit,output,i+1,ans,mapping);
            output.pop_back();
    }
}
vector<string> letterCombinations(string digits) {
        vector<string>ans;
    if(digits.length()==0){
            return ans;
    }
    int i=0;
    string output;
    string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    solve(digits,output,i,ans,mapping);
    return ans;
        
}
int main(){
    string digits="23";
    vector<string>ans=letterCombinations(digits);
    for(auto &ch:ans){
        cout<<ch<<" ";
    }

}