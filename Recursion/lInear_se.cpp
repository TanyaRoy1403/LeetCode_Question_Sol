#include<bits/stdc++.h>
using namespace std;
bool isPresent(int arr[],int n,int x){
    if(n==0){
        return false;
    }
    if(arr[0]==x){
        return true;
    }
    isPresent(arr+1,n-1,x);

}
int main(){
    int arr[]={1,2,4,5,6};
    bool result=isPresent(arr,5,10);
    if(result){
        cout<<"present"<<endl;
    }
    else{
        cout<<"Not present"<<endl;
    }
}
