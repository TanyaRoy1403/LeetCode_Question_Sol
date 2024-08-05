#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> ans;
        int m = potions.size();
        for (int& v : spells) {
            int i = lower_bound(potions.begin(), potions.end(), success * 1.0 / v) - potions.begin();
            ans.push_back(m - i);
        }
        return ans;
}
int main(){
    vector<int>spells={5,1,3};
    vector<int>potions={1,2,3,4,5};
    vector<int>ans=successfulPairs(spells,potions,7);
    for(auto it:ans){
        cout<<it<<" ";
    }
}