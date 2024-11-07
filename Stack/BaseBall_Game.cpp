#include<iostream>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

/*You are keeping the scores for a baseball game with strange rules. At the beginning of the game, you start with an empty record.

You are given a list of strings operations, where operations[i] is the ith operation you must apply to the record and is one of the following:

An integer x.
Record a new score of x.
'+'.
Record a new score that is the sum of the previous two scores.
'D'.
Record a new score that is the double of the previous score.
'C'.
Invalidate the previous score, removing it from the record.
Return the sum of all the scores on the record after applying all the operations.*/

int solve(vector<string>& s) {
    stack<int> st;
    int sum = 0;

    for (auto& ch : s) {
        if (ch == "C") {
            if (!st.empty()) {
                sum -= st.top(); // Remove the top element from the sum
                st.pop();        // Remove the top score
            }
        } 
        else if (ch == "D") {
            if (!st.empty()) {
                int doubleVal = 2 * st.top(); // Double the top element
                sum += doubleVal;
                st.push(doubleVal);
            }
        } 
        else if (ch == "+") {
            if (st.size() >= 2) {
                int first = st.top();   // Get the top score
                st.pop();
                int second = st.top();  // Get the second top score
                st.push(first);         // Restore the top score

                int sum_val = first + second;
                sum += sum_val;
                st.push(sum_val);       // Push the new sum onto the stack
            }
        } 
        else {
            int num = stoi(ch);   // Convert string to integer
            sum += num;
            st.push(num);         // Push the integer score to the stack
        }
    }

    return sum;
}

int main() {
    vector<string> arr = {"5", "2", "C", "D", "+"};
    cout << solve(arr); // Output should be 30
}
