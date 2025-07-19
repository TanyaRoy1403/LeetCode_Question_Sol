#include<iostream>
#include<vector>
using namespace std;
/**/

int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        vector<int>gapArray;
        //iss array ko bhrte h jitne v gap bn rhe h 
        //ith event
        //ith start - i-1th ka end =  gap duration
        gapArray.push_back(startTime[0]-0);
        for(int i=1;i<startTime.size();i++){
            gapArray.push_back(startTime[i]-endTime[i-1]);
        }
        //last gap
         gapArray.push_back(eventTime - endTime[endTime.size()-1]);
        //slidning window of size k+1 as maximum gap can create is k+1
        int maxSum=0;
        int currSum=0;
        int i=0,j=0;
        while(j<gapArray.size()){
            currSum+=gapArray[j];
            //shrink windo when size increase form k+1
            if(i<gapArray.size()&&j-i+1>k+1){
                currSum-=gapArray[i];
                i++;
            }
            maxSum=max(currSum,maxSum);
            j++;
        }
        return maxSum;

        
}
int main(){
    
}