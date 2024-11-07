#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*You are given two positive integer arrays spells and potions, of length n and m respectively, 
where spells[i] represents the strength of the ith spell and potions[j] represents the strength of the jth potion.

You are also given an integer success. A spell and potion pair is considered successful if the product of their strengths is at least success.

Return an integer array pairs of length n where pairs[i] is the number of potions that will form a successful pair with the ith spell.*/

/*//&-------------------------Brute force-------------------------------------------------*/

vector<int> solve(vector<int>&spells,vector<int>&potions,long long succ){
    vector<int>ans;
    int n=spells.size();
    int m=potions.size();
    int i=0;
    while(i<n){
        int count=0;
        for(int j=0;j<m;j++){
            if(potions[j]*spells[i]>=succ){
                count++;
            }
        }
        ans.push_back(count);
        i++;
    }
   
    return ans;
}

/*//&--------------------------------------------optimal-->binary search---------------------------------------------*/

vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
    vector<int> ans;
    int n = spells.size();
    int m = potions.size();
    
    // Sort the potions array
    sort(potions.begin(), potions.end());
    
    for (int i = 0; i < n; i++) {
        // Binary search to find the first potion that satisfies the condition
        int left = 0, right = m - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            // Use long long to avoid overflow
            if (static_cast<long long>(spells[i]) * potions[mid] >= success) {
                right = mid - 1;  // Search in the left half
            } else {
                left = mid + 1;  // Search in the right half
            }
        }
        // All potions from `left` to the end are valid
        ans.push_back(m - left);
    }

    return ans;
        
}
int main(){
    vector<int>spells={3,1,2};
    vector<int>potions={8,5,8};
    int succ=16;
    vector<int>ans=solve(spells,potions,succ);
    for(auto&it:ans){
        cout<<it<<" ";
    }
}