#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
There are n friends that are playing a game. The friends are sitting in a circle and are numbered from 1 to n in clockwise order. 
More formally, moving clockwise from the ith friend brings you to the (i+1)th friend for 1 <= i < n, 
and moving clockwise from the nth friend brings you to the 1st friend.

The rules of the game are as follows:

Start at the 1st friend.
Count the next k friends in the clockwise direction including the friend you started at. 
The counting wraps around the circle and may count some friends more than once.

The last friend you counted leaves the circle and loses the game.
If there is still more than one friend in the circle, go back to step 2 starting from the 
friend immediately clockwise of the friend who just lost and repeat.

Else, the last friend in the circle wins the game.
Given the number of friends, n, and an integer k, return the winner of the game.--Input: n = 5, k = 2
Output: 3--*/

/*-----------------------approach:1(SIMULATION)-------------------------------without recurssion-------------------------------------*/
int circular_game(int n,int k){
    //^create vector
    vector<int>arr;
    for(int i=1;i<=n;i++){
        arr.push_back(i);
    }
    int i=0; //!index of element where game is to be start
    while(arr.size()>1){
        int idx=(i+k-1)%arr.size(); //~index of element that will goining to remove , % will give wrap around
        arr.erase(arr.begin()+idx);
        //^reset i, ko i== idx jaha se element delete hua tha 
        i=idx;
    }
    return arr[0];
/*
*Time complexity:O(N sq)
*Space complexity:O(N)--*/
}
/*-------------------------------------------------------------approach:2(SIMULATION WITH QUEUE)-------------------------------------------------*/
int solve(int n,int k){
    queue<int>que;
    for(int i=1;i<=n;i++){
        que.push(i);
    }
    while(que.size()>1){
       for(int i=1;i<=k-1;i++){
        que.push(que.front()); //^ k se phele wale sare ele ko queue ke piche push kr deyege
        que.pop();
      }
    que.pop();
   }
   return que.front();
}
/*
*Time complexity:O(N *k)
*Space complexity:O(N)--*/
int main(){
    int n=5;
    int k=2;
    cout<<circular_game(n,k)<<endl;
    cout<<solve(n,k);
}