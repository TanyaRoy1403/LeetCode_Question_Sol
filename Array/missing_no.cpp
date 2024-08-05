#include<bits/stdc++.h>
using namespace std;
// int missing_no(vector<int>&arr,int n){
        ///using XOR
        ///XORing value in the range [0,n]
//        int sum=0;
//        for(int i=0;i<=n;i++){
//            sum=sum^i;
//        }
//        ///XORing sum with each ele of arr
//        for(auto it:arr){
//            sum=sum^it;
//        }
//        return sum;
///using sum of n natural number
//     int actual_sum=(n*(n+1))/2;
//     int getting_sum=0;
//     for(int i=0;i<n;i++){
//         getting_sum+=arr[i];
//     }
//     int missing_no=actual_sum-getting_sum;
//         return missing_no;
// }
//int binary_a(vector<int>&arr){
//    int n=arr.size();
//    sort(arr.begin(),arr.end());
//    int s=0;
//    int e=n-1;
//    int index=n;
//    while(s<=e){
//        int mid=s+(e-s)/2;
//        if(arr[mid] > mid){
//            index=mid;
//            e=mid-1;
//        }else{
//            s=mid+1;
//        }
//    }
//    return index;
//}
int binary_b(vector<int>&arr){
    int n=arr.size();
    sort(arr.begin(),arr.end());
    if(arr[n-1]!=n) return n; ///agr last wala hi missing hua to
    for(int i=0;i<n;i++){
        if(arr[i]!=i){
            return i;
        }
    }
    return -1;
}
int main(){
    vector<int>arr={3,0,1};
    int n=3;
    // cout<<missing_no(arr,n);
//    cout<<binary(arr);
    cout<<endl;
    cout<<binary_b(arr);
}
