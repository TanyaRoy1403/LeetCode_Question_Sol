#include<iostream>
#include<vector>
using namespace std;

/*Given an integer array arr, return true if there are three consecutive odd numbers in the array. Otherwise, return false.*/
//concept-->count and reset 
bool con_odd(vector<int>&arr){
    int count=0;
    int n=arr.size();
    for(int i=0;i<n;i++){
        if(arr[i]%2!=0){
            count++; //count
        }else{
            count=0;  //reset
        }
        if(count==3){
            return true;
        }
    }
    return false;

/*-------Time Complexity: O(n)
Space Complexity: O(1)----------*/

}
int main(){
    vector<int>arr={2,6,4,1};
    cout<<con_odd(arr);
}