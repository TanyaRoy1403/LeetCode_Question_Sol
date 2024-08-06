#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

/*You are given a string word containing lowercase English letters.

Telephone keypads have keys mapped with distinct collections of lowercase English letters, which can be used to 
form words by pushing them. For example, the key 2 is mapped with ["a","b","c"], we need to push the key one time to type "a", 
two times to type "b", and three times to type "c" .

It is allowed to remap the keys numbered 2 to 9 to distinct collections of letters. The keys can be remapped to 
any amount of letters, but each letter must be mapped to exactly one key. You need to find the minimum number of times 
the keys will be pushed to type the string word.

Return the minimum number of pushes needed to type word after remapping the keys.

An example mapping of letters to keys on a telephone keypad is given below. Note that 1, *, #, and 0 do not map to any letters.

*/

int minimumPushes(string word) {
        vector<int>count_arr(26,0);
        int count_pushes=0;
        for(auto &ch:word){
            count_arr[ch-'a']++;
        }
        sort(begin(count_arr),end(count_arr),greater<int>()); //^ time complexity:O(1)
        for(int i=0;i<26;i++){

            if(count_arr[i]==0) break;
            count_pushes+= (i/8+1)*count_arr[i];
        }
        return count_pushes;
        
}
/*Time comlexity:O(n)--
----------Space complexity:O(1)---------------------------*/

int main(){
    string word="abcde";
    cout<<minimumPushes(word);
}
