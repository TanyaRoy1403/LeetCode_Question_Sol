#include<iostream>
using namespace std;
bool check_pali(string st,int s,int e){
    ///base case
    if(s>=e){
        return true;
    }
    if(st[s]!=st[e]){
        return false;
    }
    else{
        return  check_pali(st,s+1,e-1);
    }
}
int main(){
    string st="121";
    int s=0;
    int e=2;
    cout<<check_pali(st,s,e);
}
