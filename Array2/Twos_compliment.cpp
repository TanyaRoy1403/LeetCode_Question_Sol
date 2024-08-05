#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> solve(vector<int>arr){
    //^flipping
    for(int i=0;i<arr.size();i++){
        if(arr[i]==1){
            arr[i]=0;
        }
        arr[i]=1;
    }
    //^vector
    int n=arr.size();
    vector<int>ans(n+1);
    //^add one to arr
    int sum=0;
    int carry=1;  //*kyu hme one add krna hi h
    for(int i=n-1;i>=0;i++){
        sum+=carry+arr[i];
        arr[i]=sum%2;
        carry/=2;
        if(carry==0){
            break;;
        }
    }
    if(carry==1){
        ans.insert(ans.begin(),1);
    }
    return ans;
}
int main(){
    vector<int>arr={1,0,10};
    vector<int>ans=solve(arr);
    for(auto &ch:ans){
        cout<<ch;
    }
}