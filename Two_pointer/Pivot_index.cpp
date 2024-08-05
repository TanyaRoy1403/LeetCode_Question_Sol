#include<iostream>
#include<string>
#include<vector>
using namespace std;
/*Given a positive integer n, find the pivot integer x such that:

The sum of all elements between 1 and x inclusively equals the sum of all elements between x and n inclusively.
Return the pivot integer x. If no such integer exists, return -1. It is guaranteed that 
there will be at most one pivot index for the given input.*/

int pivot_indx(int n){
    int leftPointer=1;     //^arr bnega --> 1,2,3,4,...n
    int rightPointer=n;
    int leftSum=0;
    int rightSum=0;
    while(leftPointer<rightPointer){
        if(leftSum<rightSum){
            leftSum+=leftPointer;
            leftPointer++;
        }else{
            rightSum+=rightPointer;
            rightPointer--;
        }
        if(leftSum==rightSum && leftPointer==rightPointer){
            return leftPointer;
        }
    }
    return -1;
}
int main(){
    int n=8;
    cout<<pivot_indx(n);
}
