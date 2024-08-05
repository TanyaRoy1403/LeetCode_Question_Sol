#include<iostream>
#include<vector>
using namespace std;
vector<int> solve_1(vector<int>&arr){
    //suffix and prefix product alg alg
    int n=arr.size();
    vector<int>pre(n,1);
    vector<int>suf(n,1);      //t.c-->O(n);
    vector<int>ans(n);       //s.c-->O(n);
    pre[0]=arr[0];
    suf[n-1]=arr[n-1];
    for(int i=1;i<arr.size();i++){
        pre[i]=pre[i-1]*arr[i];
    }
    for(int i=n-2;i>=0;i--){
        suf[i]=suf[i+1]*arr[i];
    }
    ans[0]=suf[1];
    ans[n-1]=pre[n-2];
    for(int i=1;i<=n-2;i++){
        ans[i]=pre[i-1]*suf[i+1];

    }

return ans;
}
vector<int>solve_2(vector<int>&arr){
    //prefix product ko alg na use kr ke phele ans me hi rrkh leyeg fir sufix nikal ke ans se multipy kr deye
    int n=arr.size();    
    vector<int>ans(n,1);          //t.c->O(n);
    int product=1;                //s.c->O(1)
    for(int i=1;i<=n;i++){
        ans[i]=product;
        product*=arr[i];
    }
    int sufix=1;
    for(int i=n-1;i>=0;i--){
        ans[i]*=sufix;
        sufix*=arr[i];
    }
return ans;
}
int main(){
    vector<int>arr={1,2,3,4};
    int n=arr.size();
    vector<int>ans=solve_2(arr);
    for(auto it:ans){
        cout<<it<<" ";
    }

}