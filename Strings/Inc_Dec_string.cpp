#include<iostream>
#include<vector>
#include<string>
using namespace std;
string sortString(string s) {
        vector<int> frequency(26, 0);
        for (char c : s) {
            ++frequency[c - 'a'];  // Increment the count of the current letter
        }
      
        // Initialize the answer string
        string result = "";
      
        //^jb tk tb tk result or string ka size same na ho jaye
        while (result.size() < s.size()) {

            //^Append characters chhota wala ko phele krna h a-->z
            for (int i = 0; i < 26; ++i) {
                if (frequency[i] > 0) {  // Check if the character is present
                    result += (i +'a'); // Convert index to char and append
                    --frequency[i];      // Decrement the frequency of the used character
                }
            }

            //^Append characters fir bda wala to append krna h z-->a
            for (int i = 25; i >= 0; --i) {
                if (frequency[i] > 0) {  // Check if the character is present
                    result += (i + 'a'); // Convert index to char and append
                    --frequency[i];      // Decrement the frequency of the used character
                }
            }
        }
        return result;
    }
int main(){
     string s="aaaabbbbcccc";
     cout<<sortString(s);
}