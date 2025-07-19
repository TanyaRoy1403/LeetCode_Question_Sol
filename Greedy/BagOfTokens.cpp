#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int BOT(vector<int>&tokens, int power){
    //two pointers and greedy
    int n=tokens.size();
    int score=0, maxscore=0;
    sort(tokens.begin(),tokens.end());
    int s=0;
    int e=n-1;
    while(s<=e){
        if(power>=tokens[s]){
            power-=tokens[s];
            score++;
            s++;
            maxscore=max(maxscore,score);
        }else if(score>=1){
            power+=tokens[e];
            score-=1;
            e--;
        }else{
            return  maxscore;
        }
    }
    return maxscore;
}
int main(){
    vector<int>tokens ={100,200,300,400};
    int power=200;
    cout<<BOT(tokens,power);
    return 0;
}