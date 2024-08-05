#include<iostream>
using namespace std;
int sum_nat(int n){
    if(n==0){
        return 0;
    }
    int smallAns=sum_nat(n-1);
    return smallAns+n;
}
int main(){
    int n=10;

    cout<<sum_nat(n);
}

