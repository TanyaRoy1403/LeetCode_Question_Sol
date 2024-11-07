#include<iostream>
#include<stack>
#include<vector>
using namespace std;

/*Given two integer arrays pushed and popped each with distinct values, return true if this could have been the result of a sequence of push and pop operations on an initially empty stack, 
or false otherwise.*/

/*------------------------------------------------------Brute force(backtracking)----------------------------------*/
//pushed vector ka sare ele ke pass do options h ya to stack me push ho jaye ya to pop ho jaye
//pop hone ke liye popped vector ka ele stack ke top pe hona chaiye
//backtrack -->st.pop()(backtrack) jb pushed vector ka ele stack pe push ho ,pop isliye krege (backtrack) taki hm original pushed vector tk chle jaye or next ele ko dekhe
//backtrack--> st.push()(bakctrack) jb popped vector ka ele stck ke top se match ho jayega to pop kryeg elekin next ele ko check krne ke liye original popped vector ko maitian krna hoga isliye backtrack(st.push())

bool solve_brute(vector<int>&pushed,vector<int>&popped,stack<int>&st,int i,int j){
    int m=pushed.size();  //size same hona chaiye pushed or popped ka
    //base case
    if(i==m&&j==m){
        //initially stack must be empty
        return st.empty();
    }
    //har ele ke pass do option h 
    //1 push ka
     if(i<m){
        st.push(pushed[i]);
        if(solve_brute(pushed,popped,st,i+1,j)){
            return true;
        }
        //backtrack
        st.pop();
     }
     //2 popped
     //pop hone ke st.top==popped[j]
     if(!st.empty()&&j<m&&st.top()==popped[j]){
        int store=st.top();
        st.pop();
        if(solve_brute(pushed,popped,st,i,j+1)){
            return true;
        }
        //backtrack
        st.push(store);
     }
     return false;
}
bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        return solve_brute(pushed, popped, st, 0, 0);
}
int main(){
    vector<int>psuhed={1,2,3,4,5};
    vector<int>popped={5,4,3,2,1};
    bool result=validateStackSequences(psuhed,popped);
    if(result){
        cout<<"TRUE"<<endl;
    }else{
        cout<<"FALSE"<<endl;
    }
}