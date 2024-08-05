#include<iostream>
#include<vector>
#include<string>
using namespace std;
/*You own a Goal Parser that can interpret a string command. The command consists of an alphabet of "G", "()" and/or "(al)" in some order. The Goal Parser will interpret "G" as the string "G", "()" as the string "o", and "(al)" as the string "al". The interpreted strings are then concatenated in the original order.

Given the string command, return the Goal Parser's interpretation of command.Input: command = "G()(al)"

Output: "Goal" */
//^ "G"-->"G",'()'-->"o", "(al)-->al"
//! i-> '(' and i+1--> ')' replace "o" ,i+=2
//! i--> '(' and subtr(i,4)-->'al)' replace "al", i+=3;
string interpret(string command) {
        string result = "";
        for (int i = 0; i < command.size(); i++) {
            if (command[i] == 'G') {
                result += 'G';
            } else if (command[i] == '(' && command[i + 1] == ')') {
                result += 'o';
                i++; //* Skip the next character ')'
            } else if (command[i] == '(' && command.substr(i, 4) == "(al)") {
                result += "al";
                i += 3; //*Skip the next three characters 'al)'
            }
        }
        return result;
}
int main(){
    string s="G()(al)";
    cout<<interpret(s);
}
