#include<iostream>
#include<vector>
using namespace std;
int remove_dup(vector<int>&arr){   ///return number of unique element and donot use extra space all are done in same arr
    int n=arr.size();
    int i=0,j=1;
    while(j<n){
        if(arr[i]==arr[j]){
            j++;
        }
        else{
            i++;
            arr[i]=arr[j];
        }

    }
    return i+1;
}
int main(){

    vector<int>arr={0,0,1,1,1,2,2,3,3,4};
    int n=arr.size();
    cout<<remove_dup(arr);
}
