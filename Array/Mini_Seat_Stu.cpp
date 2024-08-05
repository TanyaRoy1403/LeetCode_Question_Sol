#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int min_seat(vector<int>&seats,vector<int>&students){
    int max_seat=0;
    int max_stu=0;
    int move=0;
    for(auto &it:seats){
        max_seat=max(max_seat,it);
    }
    for(auto &it:students){
        max_stu=max(max_stu,it);
    }
    int max_len=max(max_seat,max_stu);   ///even if can use only this
    int max_final=seats.size()+students.size()+max_len;
    vector<int>Seat_count(max_final+1,0);  /// instead of max_final we can use max_len+1 it is also correct
    vector<int>stu_count(max_final+1,0);
    for(auto &it:seats){
        Seat_count[it]++;
    }
    for(auto &it:students){
        stu_count[it]++;
    }
    int i=0,j=0;
    while(i<=max_final&&j<=max_final){
        if(Seat_count[i]==0)i++;
        if(stu_count[j]==0)j++;
        if(i<=max_final&&j<=max_final&&Seat_count[i]!=0&&stu_count[j]!=0){
            move+=abs(i-j);
            Seat_count[i]--;
            stu_count[j]--;

        }
    }
    return move;

}
int main(){
    vector<int>seats={4,1,5,9};
    vector<int>student={1,3,2,6};
    cout<<min_seat(seats,student);

}
