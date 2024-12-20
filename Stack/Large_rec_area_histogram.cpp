#include<iostream>
#include<vector>
#include<stack>
#include<climits>
using namespace std;

/*Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, 
return the area of the largest rectangle in the histogram.*/


void nextSmallIndex(vector<int>&heights,vector<int>&nextAns){
    stack<int>s;
    s.push(-1);
    //piche se chleyeg
    for(int i=heights.size()-1;i>=0;i--){
        int currele=heights[i];
        while(s.top()!=-1&&heights[s.top()]>=currele){
            s.pop();
        }
        nextAns[i]=s.top();
        s.push(i);  //index store kr rhe h
    }
}
void prevSmallIndex(vector<int>&heights,vector<int>&prevAns){
    stack<int>s;
    s.push(-1);
    //piche se chleyeg
    for(int i=0;i<heights.size();i++){
        int currele=heights[i];
        while(s.top()!=-1&&heights[s.top()]>=currele){
            s.pop();
        }
        prevAns[i]=s.top(); 
        s.push(i);  //index store kr rhe h
    }
}

int lareg_are(vector<int>&height){
    vector<int> nextAns(height.size());
    vector<int> prevAns(height.size());
    nextSmallIndex(height,nextAns);

    //kyu kii hm next small ele ka index na milne pe  -1 store kr rhe jo ki glt h ,index wohi v next kv neagtive nhi ho skta h
    //isliye hm -1 ke jgh me height ka size  store krege
    for(int i=0;i<nextAns.size();i++){
        if(nextAns[i]==-1){
            nextAns[i]=height.size();
        }
    }
    prevSmallIndex(height,prevAns);
    int max_area=INT_MIN;
    for(int i=0;i<height.size();i++){
        int width=nextAns[i]-prevAns[i]-1;
        int hei=height[i];
        int curr_area=width*hei;
        max_area=max(max_area,curr_area);
    }
    return max_area;
}
int main(){
    vector<int>height={2,1,5,6,2,3};
    cout<<lareg_are(height);
    return 0;
}