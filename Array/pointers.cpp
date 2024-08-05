
#include<iostream>
#include<vector>
using namespace std;
int main(){
    // int a[5]={1,2,3,4,5};
    // int* ptr=a;
    // cout<<ptr<<endl;
    // cout<<&a<<endl;
    int* p[5];
    int b;
    p[2]=&b;  //^pointer numbeer 2 store add of b
    cout<<p[2]<<endl;
    cout<<&b<<endl;

}