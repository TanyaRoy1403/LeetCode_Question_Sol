#include<iostream>
#include<vector>
using namespace std;

int binarySearch(int nums[],int low,int high,int target){
    while(low<=high){
        int mid=low+(high-low)/2;
        if(nums[mid]==target){
            return mid;
        }
        else if(nums[mid]>target){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return -1;
}
int search(int nums[], int target) {
    int low=0,high=1;
    //searching the range in which the target lies
    while(nums[high]<target){
        low=high;
        high=high*2;
    }
    // while(low<=high){
    //     int mid=low+(high-low)/2;
    //     if(nums[mid]==target){
    //         return mid;
    //     }
    //     else if(nums[mid]>target){
    //         high=mid-1;
    //     }
    //     else{
    //         low=mid+1;
    //     }
    // }
    return binarySearch(nums,low,high,target);
    return -1;
}
int main(){
    int nums[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int target=14;
    cout<<search(nums,target)<<endl;
    return 0;
}
