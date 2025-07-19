#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*Given two arrays start[] and end[] such that start[i] is the starting time of ith meeting and end[i] is the ending time of ith meeting. 

Return the minimum number of rooms required to attend all meetings.*/

int minMeeting(vector<int>&start,vector<int>&ends){
    sort(begin(start),end(start));
    sort(begin(ends),end(ends));

    int count=0;
    int endsidx=0;
    for(int i=0;i<start.size();i++){
        if(start[i]<ends[endsidx]){
            count++; //nya room chaiye 
        }else{
            endsidx++;  //ussi room ko reuse kr rhe h
        }
    }
    return count;
}
int main(){
    vector<int>start={1,5,15};
    vector<int>end={18,12,17};
    cout<<minMeeting(start,end);
}