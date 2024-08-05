#include<iostream>
#include<string>
using namespace std;
/*Given a valid (IPv4) IP address, return a defanged version of that IP address.

A defanged IP address replaces every period "." with "[.]".*/

string defangIPaddr(string address) {
        for(int i=0;i<address.size();i++){
            if(address[i]=='.'){
                address.replace(i,1,"[.]");  //strin_name.replace(start indx,no of char to be replace, with whom to replace)
                i+=2;
            }
        }
        return address;
}
/*-------------------------without using stl-----------------------------------------------------*/
string solve(string s){
    string result="";
    for(auto c:s){
        if(c=='.'){
            result+="[.]";
        }else{
            result+=c;
        }
    }
    return result;
}
int main(){
    string s="1.1.1.1";
    cout<<defangIPaddr(s);
    cout<<endl;
    cout<<solve(s);
}