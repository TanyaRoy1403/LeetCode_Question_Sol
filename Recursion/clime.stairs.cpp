#include<iostream>
using namespace std;
int ways(int n){
    if(n==0||n==1){
        return 1;
    }
    if(n<0){
        return 0;
    }
    return ways(n-1)+ways(n-2);
}

///tower of honoi
int toh(int  n){
    if(n==0){
    return 0;}
    return toh(n-1)+1+toh(n-1);
}
int main(){
    int n=4;
    cout<<ways(n)<<endl;

    cout<<toh(n);
}



