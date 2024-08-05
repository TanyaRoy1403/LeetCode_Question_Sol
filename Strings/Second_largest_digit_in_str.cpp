#include<iostream>
#include<string>
#include<ctype.h>
using namespace std;
/*Given an alphanumeric string s, return the second largest numerical digit that appears in s, or -1 if it does not exist.

An alphanumeric string is a string consisting of lowercase English letters and digits.Input: s = "dfa12321afd"
Output: 2*/

int sec_largest(string s){
    int largest=-1;
    int sec_largest=-1;
    for(const char &ch:s){
        if(isdigit(ch)){
            int value=ch-'0'; //^to convert char into digit
        if(value>largest){
            sec_largest=largest;
            largest=value;
        }else if(value>sec_largest&&value<largest){
            sec_largest=value;
        }
        }
    }
    return sec_largest;
}
int main(){
    string s="abc1111";
    cout<<sec_largest(s);
}