#include<iostream>
#include<vector>
using namespace std;

/*At a lemonade stand, each lemonade costs $5. Customers are standing in a queue to buy from you and order one 
at a time (in the order specified by arr). Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill. 
You must provide the correct change to each customer so that the net transaction is that the customer pays $5.

Note that you do not have any change in hand at first.

Given an integer array arr where arr[i] is the bill the ith customer pays, return true if you can provide every 
customer with the correct change, or false otherwise.*/


bool solve(vector<int>&arr){
    int n=arr.size();
    int five = 0;
    int ten  = 0;
    for(int &bill : arr) {
        if(bill == 5) {
            five++;
        } else if(bill == 10) { //return 5$ to customer
            if(five > 0) {
                five--;
                ten++;
            } else {
                return false;
            }
        } else if(five > 0 && ten > 0) { //return 15$ to customer
            five--;
            ten--;
        } else if(five >= 3) { //5, 5, 5
            five -= 3;
        } else {
            return false;
        }
    }
    return true;

}
int main(){
    vector<int>arr={5,5,10,10,20};
    bool result=solve(arr);
    if(result){
        cout<<"yess"<<endl;
    }else
    cout<<"no"<<endl;
}