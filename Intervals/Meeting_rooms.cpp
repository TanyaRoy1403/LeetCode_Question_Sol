#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

/*You are given an array of meeting time intervals intervals where intervals[i] = [start_i, end_i].

Return true if a person can attend all meetings, otherwise return false.*/

bool canAttendMeetings(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    for (int i = 1; i < intervals.size(); ++i) {
        if (intervals[i][0] < intervals[i - 1][1]) {
            return false; // Overlapping
        }
    }
    return true;
}

int main(){
    vector<vector<int>>time={{0,30},{5,10},{15,20}};
    bool res=canAttendMeetings(time);
    cout<<res<<endl;
}