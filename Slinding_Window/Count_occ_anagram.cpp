#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;


/* //*Given a word pat and a text txt. Return the count of the occurrences of 
anagrams of the word in the text.*/




// Function to check if all values in the map are zero

/*//^----------------------------------------------Brute Force--------------------------------------------------------------------------------------------*/
bool allZero(const unordered_map<char, int>& freqMap) {
    for (const auto& pair : freqMap) {
        if (pair.second != 0) {
            return false;
        }
    }
    return true;
}

int count_occ(string text, string pat) {
    int patLen = pat.length();
    int txtLen = text.length();
    int count = 0;
  

    for (int i = 0; i <= txtLen - patLen; ++i) {
        unordered_map<char, int> mp;
        for (char ch : pat) {
            mp[ch]++;
        }
        for (int j = i; j < i + patLen; ++j) {
            if (mp.find(text[j]) != mp.end()) {
                mp[text[j]]--;
            }
        }
        if (allZero(mp)) {
            count++;
        }
    }

    return count;
/*//^----time complexity:O(patlen*txtlen)-----
-//^---space compllexity: O(txtlen)-------------------------------------------------------------------------------------------------*/
}

/*//^---------------------------------------------------less space----------------------------------------------------------*/
bool allZero2(const vector<int>& freqMap) {
    for (const auto& val : freqMap) {
        if (val != 0) {
            return false;
        }
    }
    return true;
}

int count_occ2(string text, string pat) {
    int patLen = pat.length();
    int txtLen = text.length();
    int count = 0;

    for (int i = 0; i <= txtLen - patLen; ++i) {
        vector<int> count_arr(26, 0); //^Frequency array for letters a-z  space complexity O(1)
        for (char ch : pat) {
            count_arr[ch - 'a']++;
        }
        for (int j = i; j < i + patLen; ++j) {
            count_arr[text[j] - 'a']--;
        }
        if (allZero2(count_arr)) {
            count++;
        }
    }

    return count;

/*//^----time complexity:O(patlen*txtlen)-----
-//^---space compllexity: O(1)-------------------------------------------------------------------------------------------------*/
}




/*//^----------------------------------------------------------optimal solution-->slinding window--------------------------------------------------*/

bool allZero(const vector<int>& freqMap) {
    for (const auto& pair : freqMap) {
        if (pair != 0) {
            return false;
        }
    }
    return true;
}

int count_ana(string text,string pat){
    vector<int>count_arr(26,0);
    int n=text.length();
    int k=pat.length();
    int i=0,j=0;
    int count=0;
    for(auto &ch:pat){
        count_arr[ch-'a']++;
    }
    while(j<n){
        count_arr[text[j]-'a']--; ///*agr j wale indx pe wohi char h jo pat me h
        if(j-i+1==k){
            if(allZero(count_arr)){
                count++;

            }
            count_arr[text[i]-'a']++;  //*jo window se bhahr ho gya uska count increase kr to count_arr me
            i++;  //*window slide
        }
        j++;  //*window slid
    }
    return count;
/*//^----time complexity:O(n)-----
-//^---space compllexity: O(1)-------------------------------------------------------------------------------------------------*/
}
int main() {
    string text = "aabaabaa";
    string pat = "aaba";
    cout << count_ana(text, pat); 
    cout<<endl;
    cout<<count_occ2(text,pat);
    return 0;
}
