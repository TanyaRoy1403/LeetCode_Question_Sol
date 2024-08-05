#include<iostream>
#include<vector>
using namespace std;
//brute force
//peak-->strictly greter its neighbouring ele
int peak_ele(vector<int>&arr){
    int n=arr.size();
    int indx=-1;
    for(int i=0;i<n;i++){
        if(arr[i-1]<arr[i]&&arr[i]>arr[i+1]){
            cout<< arr[i];
        }
    }
    return -1;
}
int main(){
    vector<int>arr={10,20,70,60,50,40,30};
    peak_ele(arr);
    // if(ans){
    //     cout<<"find"<<endl;
    // }else{
    //     cout<<"not"<<endl;
    // }
}