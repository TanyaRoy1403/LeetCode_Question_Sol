#include<iostream>
#include<math.h>
using namespace std;
int power_no(int a,int b){
    ///base case
    if(b==0){
        return 1;
    }
    if(b==1){
        return a;
    }
    int ans_even=power_no(a,b/2);
    if(b%2==0){
        return ans_even*ans_even;
    }
    else{
      return a*ans_even*ans_even;
    }

}
int main(){
    int a;
    cout<<"Value of base:"<<endl;
    cin>>a;
    int b;
    cout<<"Value of exponent:"<<endl;
    cin>>b;
    cout<<"Power of given number is:"<<power_no(a,b);
}
