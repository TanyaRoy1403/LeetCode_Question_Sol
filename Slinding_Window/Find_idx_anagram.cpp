#include<iostream>
#include<vector>
#include<string>
using namespace std;

/*Given two strings s and p, return an array of all the start indices of p's anagrams in s. 
You may return the answer in any order.Input: s = "cbaebabacd", p = "abc"
Output: [0,6]*/

/*//^-----------------------------------------Brute Force---------------------------------------------*/
bool allZero(const vector<int>& freqMap) {
    for (const auto& val : freqMap) {
        if (val != 0) {
            return false;
        }
    }
    return true;
}
// vector<int> findIdxAna(string s,string p){
//     vector<int>ans;
  
//     int n=s.length();
//     int k=p.length();
//     for(int i=0;i<=(n-k);i++){ //^O(n)
//         vector<int>count_arr(26,0);
//         for(auto &ch:p){
//             count_arr[ch-'a']++;
//         }
//         for(int j=i;j<i+k;j++){  //^ O(k)
//             count_arr[s[j]-'a']--;
//         }
//         if(allZero(count_arr)){
//             ans.push_back(i);
//         }
//     }
//     return ans;
/*//^---time complexity:(n*k)----space complexity:O(1)----------------------------------------------------------------*/
//}

/*//^---------------optimal solution-----------------------------------------------------------------------------------*/
vector<int> findIdx(string txt,string pat){
    vector<int>ans;
    vector<int>count_arr(26,0);
    int n=txt.length();
    int k=pat.length();
    int i=0,j=0;
    for(auto &ch:pat){
        count_arr[ch-'a']++;
    }
    while(j<n){
        count_arr[txt[j]-'a']--;
        if(j-i+1==k){
            if(allZero(count_arr)){
                ans.push_back(i);
            }
            count_arr[txt[i]-'a']++;
            i++;
        }
        j++;
    }
    return ans;
/*//^---Time complexity:O(n)------space complexity:O(1)----------------------------------------------------------------------*/

}
int main(){
    string s="cbaebabacd";
    string p= "abc";
    vector<int>ans=findIdx(s,p);
    for(auto &ch:ans){
       
        cout<<ch<<" ";
    }
}