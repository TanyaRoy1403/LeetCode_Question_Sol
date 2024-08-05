#include<iostream>
using namespace std;
int sqrt(int x){
    int s=0;
    int e=x;  //space
    int ans=-1;  //to store and compute
    while(s<=e){
       long long int mid=s+(e-s)/2;
       long long int product=mid*mid;
       if(product==x){
        return mid;
       }else if(product<x){  //thora jada  chaiye but jo mila h uses jane v nhi deyeg
                ans=mid;
                s=mid+1;

       }else{
        e=mid-1;
       }

    }
    return ans;

}
double sqrt_pre(int x){
    double mysqrt=sqrt(x);
    double precision=8;
    double step=0.1;
    while(precision--){
        double j=mysqrt;
        while(j*j<=x){
            mysqrt=j;
            j+=step;
        }
            step/=10;
    }
    return mysqrt;
}
int main(){
    int x=63;
    double ans=sqrt_pre(x);
    // cout<<sqrt_pre(x);
    //cout only print upto 5 precision ,to print above five precision we have to use printf fuc of c style
    printf("final answer %f",ans); 
}