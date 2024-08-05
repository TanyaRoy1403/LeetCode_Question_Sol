#include<iostream>
#include<vector>
using namespace std;
 /*There is a restaurant with a single chef. You are given an array customers, where customers[i] = [arrivali, timei]:

arrival i is the arrival time of the ith customer. The arrival times are sorted in non-decreasing order.
timei is the time needed to prepare the order of the ith customer.
When a customer arrives, he gives the chef his order, and the chef starts preparing it once he is idle. 
The customer waits till the chef finishes preparing his order. The chef does not prepare food for more than one customer at a time. 
The chef prepares food for customers in the order they were given in the input.

Return the average waiting time of all customers. Solutions within 10-5 from the actual answer are considered accepted.Input: customers = [[5,2],[5,4],[10,3],[20,1]]
Output: 3.25000*/

double wait_time(vector<vector<int>>&arr){
    int n= arr.size();  //*2d vector size
    double totalWaitTime=0;
    int currTime=0;
    for(auto &it:arr){
        int arrivalTime=it[0];
        int cookTime=it[1];
       if(currTime<arrivalTime){
           currTime=arrivalTime;
       }
       int waitTime=(currTime+cookTime)-arrivalTime;
       totalWaitTime+=waitTime;
       currTime+=cookTime;
    }
    return totalWaitTime/n;


}
int main(){
    vector<vector<int>>arr={{5,2},{5,4},{10,3},{20,1}};
    cout<<wait_time(arr);

}