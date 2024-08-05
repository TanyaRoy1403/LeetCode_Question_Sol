#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

/*Given a list of strings words and a string pattern, return a list of words[i] that match pattern. You may return the answer in any order.

A word matches the pattern if there exists a permutation of letters p so that after replacing every letter x in the pattern with p(x),
 we get the desired word.

Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, 
and no two letters map to the same letter.*/


bool matchesPattern(const string& word, const string& pat) {
    if (word.size() != pat.size()) return false;

    unordered_map<char, char> w_to_p;
    unordered_map<char, char> p_to_w;

    for (int i = 0; i < word.size(); i++) {
        char w = word[i];
        char p = pat[i];

        if ((w_to_p.count(w) && w_to_p[w] != p) || (p_to_w.count(p) && p_to_w[p] != w)) {
            return false;
        }

        w_to_p[w] = p;
        p_to_w[p] = w;
    }
    return true;
}

vector<string>findAndReplacePattern(vector<string> words, string pat) {
    vector<string> matching_words;

    for (const string& word : words) {
        if (matchesPattern(word, pat)) {
            matching_words.push_back(word);
        }
    }

    return matching_words;
}

int main() {
    vector<string> words = {"abc", "deq", "mee", "aqq", "dkd", "ccc"};
    string pattern = "abb";
    vector<string> result = findAndReplacePattern(words, pattern);
    
    // Print the result
    for (const string& word : result) {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}


