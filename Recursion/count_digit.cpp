#include<bits/stdc++.h>
using namespace std;
int count_digit(int n){
    if(n==0){
        return 0;
    }
    int smallAns=count_digit(n/10);
    return 1+smallAns;

}
int main(){
    int n=142567898;
    cout<<count_digit(n);
}
