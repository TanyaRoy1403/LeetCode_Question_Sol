#include<iostream>
#include<vector>
using namespace std;
/*Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.*/
vector<int>get_left_max(vector<int>&height,int n){
    vector<int>left_max(n);
    left_max[0]=height[0];
    for(int i=1;i<n;i++){
        left_max[i]=max(left_max[i-1],height[i]);
    }
    return left_max;

}
vector<int> get_right_max(vector<int>&height,int n){
    vector<int>right_max(n);
    right_max[n-1]=height[n-1];
    for(int i=n-2;i>=0;i--){
        right_max[i]=max(right_max[i+1],height[i]);
    }
    return right_max;
}
int rain_water(vector<int>&height){
    int n=height.size();
    int area=0;     
    int width=1;

    vector<int>left_max=get_left_max(height,n);
    vector<int>right_max=get_right_max(height,n);
    for(int i=0;i<n;i++){
        int h=min(left_max[i],right_max[i])-height[i];
        if (h > 0) {
            area += h;
        }
    }

    return area;
}
int main(){
    vector<int>height={0,1,0,2,1,0,1,3,2,1,2,1};
    cout<<rain_water(height);
    
}