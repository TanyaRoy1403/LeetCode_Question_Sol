#include<bits/stdc++.h>
using namespace std;

///brute force
//int max_sum(vector<int>& arr) {
//    int n = arr.size();
//    int maxSum = INT_MIN;
//    for (int i = 0; i < n; i++) {
//        for (int j = i; j < n; j++) {
//            int sum = 0;
//            for (int k = i; k <= j; k++) {
//                sum += arr[k];
//            }
//            maxSum = max(maxSum, sum);
//        }
//    }
//
//    return maxSum;
//}
///better
int max_sum(vector<int>& arr) {
    int n = arr.size();
    int maxSum = INT_MIN;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            maxSum = max(maxSum, sum);
        }
    }

    return maxSum;
}

///optimal--> kadanes algo
///step-->:sum+=arr[i],:maxsum->update,:if(sum<0) then sum=0;
int max_sum(vector<int>& arr) {
    int n = arr.size();
    int maxSum = INT_MIN;
    int sum = 0;
    for (int i = 0; i < n; i++) {
         sum=sum+arr[i];
            maxSum = max(maxSum, sum);
            if(sum<0){
                sum=0;
            }

    }

    return maxSum;
}
int main(){

    vector<int>arr={5,4,-1,7,8};
    int n=arr.size();
    cout<<max_sum(arr);
}
