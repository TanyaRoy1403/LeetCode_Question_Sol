#include<bits/stdc++.h>
using namespace std;
bool isPali(string &str){
    int s=0;
    int e=str.size()-1;
    while(s<e){
        if(str[s]!=str[e]){  ///str.charAt[s] and str.charAt[e]
            return false;
        }
        s++;
        e--;
    }
    return true;
}
string findPali(vector<string>&arr){
    for(auto &it:arr){
        if(isPali(it)){
            return it;
        }
    }
    return "";
}
int main(){
    vector<string>arr={"notapalindrome","racecar"};
    cout<<findPali(arr);
}
