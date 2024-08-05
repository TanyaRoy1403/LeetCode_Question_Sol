#include<bits/stdc++.h>
using namespace std;
bool sqaure_no(int c){
    ///brute force
    for(long  a=0;a<=sqrt(c);a++){
        for(long b=0;b<=sqrt(c);b++){
            if(a*a+b*b==c){
                return true;
            }
        }
    }
    return false;
}
bool sqr(int x){
    int s=0;
    int e=x;
    
}
int main(){
    long c=9;
    cout<<sqaure_no(c);
}
