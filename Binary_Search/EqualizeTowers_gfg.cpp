#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int miniCost(vector<int>&heights,vector<int>&costs){
    int n=heights.size();
    sort(begin(heights),end(heights));
    int s=*min_element(begin(heights),end(heights));
    int e=*max_element(begin(heights),end(heights));
    while(s<=e){
        int mid=s+(e-s)/2;
        
    }
}