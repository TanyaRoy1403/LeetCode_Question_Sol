#include<iostream>
#include<string>
#include<unordered_set>
#include<vector>
using namespace std;
/*International Morse Code defines a standard encoding where each letter is mapped to a series of dots and dashes, as follows:

'a' maps to ".-",
'b' maps to "-...",
'c' maps to "-.-.", and so on.
For convenience, the full table for the 26 letters of the English alphabet is given below:

[".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",
".-.","...","-","..-","...-",".--","-..-","-.--","--.."].Given an array of strings words where each word can 
be written as a concatenation of the Morse code of each letter.Return the number of different transformations among all words we have.*/

int morse_code(vector<string>&s){
    unordered_set<string>st;
    string mapping[26]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",
".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

    for(auto  &ch:s){
        string result="";
        for(auto &it:ch){
            int idx=it-'a';
            result+=mapping[idx];
        }
    st.insert(result);
    }
    return st.size();
}
int main(){
    vector<string>s={"gin","zen","gig","msg"};
    cout<<morse_code(s);
}