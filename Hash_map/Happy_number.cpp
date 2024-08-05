#include<iostream>
#include<string>
#include<unordered_set>
using namespace std;
/*Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.*/

int sumSquare(int n){
    int sum=0;
    while(n>0){
        int digit=n%10;
        sum+=digit*digit;
        n/=10;
    }
    return sum;
}

bool happy_no(int n){
    unordered_set<int>st;
    while(n!=1&& st.find(n)==st.end()){  //^number nhi mila sumSquare
        st.insert(n);  //^na milne pe insert kr do
        n=sumSquare(n);
    }
}
int main(){
    int n=19;
    bool result=sumSquare(n);
    if(result){
        cout<<"Find one:"<<endl;
    }
    else{
        cout<<"Not find:"<<endl;
    }
}