#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
/*The school cafeteria offers circular and square sandwiches at lunch break, referred to by numbers 0 and 1 respectively. All students stand in a queue. 
Each student either prefers square or circular sandwiches.

The number of sandwiches in the cafeteria is equal to the number of students. The sandwiches are placed in a stack. At each step:
If the student at the front of the queue prefers the sandwich on the top of the stack, they will take it and leave the queue.
Otherwise, they will leave it and go to the queue's end.

This continues until none of the queue students want to take the top sandwich and are thus unable to eat. 
You are given two integer arrays students and sandwiches where sandwiches[i] is the type of the i​​​​​​th sandwich in 
the stack (i = 0 is the top of the stack) and students[j] is the preference of the j​​​​​​th student in the initial queue (j = 0 is the front of the queue). 
Return the number of students that are unable to eat.*/
int solve(vector<int>&students,vector<int>&sandwich){
    stack<int>sand;
    queue<int>stud;
    int count=0;
    for(int i=sandwich.size();i>=0;i--){
            sand.push(sandwich[i]);
        }
    for(auto &it:students){
        stud.push(it);
    }
    while(!stud.empty()&&count<stud.size()){
        if(stud.front()==sand.top()){
            sand.pop();  //sandwich ko hta do
            stud.pop();  //person ko v
            count=0; 
        }else{
                int temp=stud.front();
                stud.pop();
                stud.push(temp);
                count++;
        }
    }
    return stud.size();   //jo queue me rh jayega woh nhi kha paya

}
int main(){
    vector<int>sandwiches={0,1,0,1};
    vector<int>students={1,1,0,0};
    cout<<solve(students,sandwiches);
}