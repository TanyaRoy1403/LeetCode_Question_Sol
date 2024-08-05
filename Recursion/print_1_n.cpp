#include<iostream>
using namespace std;
void print(int n){
    ///base case
    if(n<=1){
        cout<<n<<endl;
    }
    else{
        cout<<n<<endl;
        print(n-1);
    }
}
int main(){
    int n=10;
    print(n);
}
