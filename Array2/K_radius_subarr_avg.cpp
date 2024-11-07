#include<iostream>
#include<vector>
using namespace std;

/*You are given a 0-indexed array nums of n integers, and an integer k.

The k-radius average for a subarray of nums centered at some index i with the radius k is the average of all elements in nums between the indices i - k and i + k (inclusive). 
If there are less than k elements before or after the index i, then the k-radius average is -1.

Build and return an array avgs of length n where avgs[i] is the k-radius average for the subarray centered at index i.

The average of x elements is the sum of the x elements divided by x, using integer division. The integer division truncates toward zero, 
which means losing its fractional part.*/

vector<int> solve(vector<int>&arr,int k){
    int n=arr.size();

    if(k == 0)
        return arr;
    
    vector<int>ans(n, -1);
        
    if(n < 2*k + 1)
        return ans;

    //cal prefixsum
    vector<long long> preSum(n,0);
    preSum[0]=arr[0];
    for(int i=1;i<n;i++){
        preSum[i]=preSum[i-1]+arr[i];
    }
    for(int i=k;i<n-k;i++){
        int left_idx=i-k;
        int right_idx=i+k;
        long long curr_sum=preSum[right_idx]; //pura sum zero ind se le kr ke i+k tk ka sum

        if(left_idx>0){ //mtlb i ke left me aise kuch ele h jo i-k me included nhi uske sum se htna hoga
            curr_sum-=preSum[left_idx-1];

        }
        int avg=curr_sum/(2*k+1);
        ans[i]=avg;
    }
    return ans;
/*This is kind of brute force method as it takes alot of spaces ...................its optimal sol is in *****SLINDING WINDOW SECTION***-----*/
}
int main(){
    vector<int>arr={7,4,3,9,1,8,5,2,6};
    int k=3;
    vector<int>ans=solve(arr,k);
    for(auto &it:ans){
        cout<<it<<" ";
    }
}

