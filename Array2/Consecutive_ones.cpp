#include<iostream>
#include<vector>
using namespace std;
//concept-->count and reset 
int count_ones(vector<int>&arr){
    int count=0;
    int max_count=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==1){
            count++;
            max_count=max(max_count,count);
        }else{
            count=0;
        }
    }
    return max_count;

/*---------Time Complexity: O(n)
Space Complexity: O(1)---------*/

}
int main(){
    vector<int>arr={1,4,1,1,1,1};
    cout<<count_ones(arr);
}