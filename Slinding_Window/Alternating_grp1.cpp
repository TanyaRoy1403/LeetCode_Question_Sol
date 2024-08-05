#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*There is a circle of red and blue tiles. You are given an array of integers colors. 
The color of tile i is represented by colors[i]:

colors[i] == 0 means that tile i is red.
colors[i] == 1 means that tile i is blue.
Every 3 contiguous tiles in the circle with alternating colors 
(the middle tile has a different color from its left and right tiles) is called an alternating group.

Return the number of alternating groups.

Note that since colors represents a circle, 
the first and the last tiles are considered to be next to each other.*/



int solve(vector<int>&arr){
    int k=3;
    int n=arr.size();
    int i=0,j=0;
    int count=0;
    while(j<n){
        if(arr[j]!=arr[(j-1+n)%n] && arr[j]!=arr[(j+1)%n])
        count++;
        j++;
    }
    return count;
}
int main(){
    vector<int>arr={1,1,1};
    cout<<solve(arr);
}