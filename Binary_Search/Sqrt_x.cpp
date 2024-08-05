#include<iostream>
#include<vector>
using namespace std;

//Concep->Search space-->define space/range acc to input and also store and compute concept
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
int main(){
    int x=23457601;
    cout<<sqrt(x);
}