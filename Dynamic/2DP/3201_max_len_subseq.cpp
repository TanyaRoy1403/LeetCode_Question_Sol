#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*You are given an integer array nums.
A subsequence sub of nums with length x is called valid if it satisfies:

(sub[0] + sub[1]) % 2 == (sub[1] + sub[2]) % 2 == ... == (sub[x - 2] + sub[x - 1]) % 2.
Return the length of the longest valid subsequence of nums.

A subsequence is an array that can be derived from another array by deleting some or no 
elements without changing the order of the remaining elements.*/



//without using dp

//^hmare pass do case h (sub[0]+sub[1]%2)= 0 ya 1
//& 0 kb kb--> even+even , odd+odd
//!1 kb kb ayega--> odd+even, even+odd
//~(sub[0]+sub(1)%2)=0, mltb sub[0]=even , sub[1]= even , tb sub[1]+sub[2] yaha pe sub[2] ko even odd hona prega 
//~(sub[0]+sub(1)%2)=0, mltb sub[0]=odd , sub[1]= odd , tb sub[1]+sub[2] yaha pe sub[2] ko  odd hona prega
//~ ocnculsion--> rem=0 , sara paritiy ko odd ya even hona prega same same , rem=1 ke liye alternate parity ko odd even hona prega 
int maxiLength(vector<int>& nums) {
    int n=nums.size();
    int count_even=0;
    int count_odd=0;
    for(auto it:nums){
        if(it%2==0){count_even++;}
            else {count_odd++;}
    }
    int alt_length=1;
    int prev_parity=nums[0]%2; //satrtin ka ko yehi hoga n
    for(int i=1;i<n;i++){
        int curr_parity=nums[i]%2;
        if(curr_parity!=prev_parity){alt_length++;prev_parity=curr_parity;};

    }
    return max({alt_length,count_even,count_odd});
}
// tc: O(n), sc: O(1)

//using 2d dp
//bottom up

int maximumLength(vector<int>& nums) {
    //bottom up
    int dp[2][2]={};
    int len=0;
    for(auto it:nums){
        int curr_parity=it%2;
        for (int j = 0; j < 2; ++j) {
            int prev_parity = (j - curr_parity + 2) % 2; // calculate what previous parity should be
            dp[curr_parity][prev_parity] = dp[prev_parity][curr_parity] + 1; // extend the subsequence
            len = max(len, dp[curr_parity][prev_parity]);
        }
    }
    return len;
    // tc: O(n), sc: O(1)
}
int main(){
    vector<int>arr={1,2,1,1,2,1,2};
    cout<<"Without DP:"<<" ";
    cout<<maxiLength(arr)<<endl;
    cout<<"With DP:"<<" ";
    cout<<maximumLength(arr)<<endl;

}
