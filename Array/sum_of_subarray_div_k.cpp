#include<bits/stdc++.h>
using namespace std;
int sub_k(vector<int>&arr,int k){
    int  n=arr.size();
    ///breute force with cumulative sum(O(1))
    int count=0;
    ///cumulative sum
    vector<int>CumSum(n,0);
    CumSum[0]=arr[0];
    for(int i=1;i<n;i++){
            CumSum[i]=CumSum[i-1]+arr[i];
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            int sum=0;
            if(i==0){
                sum=CumSum[j];
            }
            else{
                sum=CumSum[j]-CumSum[i-1];
            }
            if(sum%k==0){
                count++;
            }
            else{
                count+=0;
            }
        }
    }
    return count;
}
int main(){
    vector<int>arr={5};
    int n=arr.size();
    cout<<sub_k(arr,9);
}
///optimal solution
int count_subrr_k(int vector<int>arr,int k){
    int n=arr.size();
    int count=0;

}
