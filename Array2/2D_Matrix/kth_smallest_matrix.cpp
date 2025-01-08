#include<iostream>
#include<vector>
using namespace std;

int kthSortedMatrix(vector<vector<int>>&nums,int k){
    int count;
    int n=nums.size();
    int m=nums[0].size();
    int low=nums[0][0];
    int high=nums[n-1][m-1];
    while(low<high){
        int mid=low+(high-low)/2;
        count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(nums[i][j]<=mid){
                    count++;
                }
            }
        }
        if(count<k){
            low=mid+1;
        }else{
            high=mid;
        }

    }
    return low;
    //time complexity is O(n*m*log(max-min))
}
//using heap
#include<queue>
int kthSortedMatrix2(vector<vector<int>>&nums,int k){
    priority_queue<int>pq;
    for(int i=0;i<nums.size();i++){
        for(int j=0;j<nums[0].size();j++){
            pq.push(nums[i][j]);
            if(pq.size()>k){
                pq.pop();
            }
        }
    }
    return pq.top();
}
//time complexity is O(n*m*log(max-min))
int main(){
    vector<vector<int>>nums={{1,5,9},{10,11,13},{12,13,15}};
    int k=8;
    cout<<kthSortedMatrix(nums,k)<<endl;
    cout<<endl;
    cout<<kthSortedMatrix2(nums,k)<<endl;
    return 0;
}