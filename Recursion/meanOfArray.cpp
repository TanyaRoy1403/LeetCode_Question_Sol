#include<iostream>
using namespace std;
int sumArray(int arr[],int n){
    if(n==0){
        return 0;
    }
    return arr[0]+sumArray(arr+1,n-1);
}
double mean_array(int arr[],int n){
    if(n==0){
        return 0;
    }
    int sum=sumArray(arr,n);
    return sum/n;
}
int main(){
    int arr[5]={1,2,3};

    cout<<mean_array(arr,3);
}
