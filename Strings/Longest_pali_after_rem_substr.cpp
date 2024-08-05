#include <iostream>
#include <string>
using namespace std;

/*Given a string str, the task is to find the longest palindromic string that can be obtained from it after removing a substring.*/

string longestPalindromeAfterRemoval(string s) {
    int st = 0;
    int e = s.length() - 1;
    string resultLeft = "";
    string resultRight = "";

    while (st <= e) {
        if (s[st] == s[e]) {
            resultLeft += s[st]; // Add the matched character to the left part
            if (st != e) {
                resultRight = s[e] + resultRight; // Add the matched character to the right part
            }
            st++;
            e--;
        } else if (s[st] != s[e]) {
            e--; // Skip the mismatched character from the right end
        }
    }

    return resultLeft + resultRight;
}

int main() {
    string s = "abacdfghidcaba";
    cout << "Longest palindromic string after removal: " << longestPalindromeAfterRemoval(s) << endl;
    return 0;
}
