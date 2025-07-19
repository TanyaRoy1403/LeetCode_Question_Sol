#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int candy(vector<int>ratings){
    //approoach 1
    ///traveerse Left to Right and then right to left and then compare value at i for both traverse and store max of them
    int n=ratings.size();
    vector<int>LR(n,1);
    vector<int>RL(n,1);
    for(int i=1;i<n;i++ ){
        if(ratings[i]>ratings[i-1]){
            LR[i]=max(LR[i],LR[i-1]+1);
        }

    }
    //traverse right to left
    for(int i=n-2;i>=0;i--){
        if(ratings[i]>ratings[i+1]){
            RL[i]=max(RL[i],RL[i+1]+1);
        }
    }
    //compare
    int ans=0;
    for(int i=0;i<n;i++){
        ans+=max(LR[i],RL[i]);
    }
    return ans;
    
}
//approach 2
//use only one array 
int candy2(vector<int>ratings){
    int n=ratings.size();
    vector<int>count(n,1);
    //lr
    for(int i=1;i<n;i++){
        if(ratings[i]>ratings[i-1]){
            count[i]=max(count[i],count[i-1]+1);
        }
    }
    for(int i=n-2;i>=0;i--){
        if(ratings[i]>ratings[i-1]){
            count[i]=max(count[i],count[i-1]+1);
        }
    }
    return accumulate(begin(count),end(count),0);
}

int main(){
    vector<int>ratings={1,2,2};
    cout<<candy(ratings);
}