#include<iostream>
#include<vector>
#include<string>
using namespace std;
#include<algorithm>

//^using mapping
//*[128,64,32,16,8,4,2,1]

vector<int> decimal_to_binary(int n){
    int mapping[8]={128,64,32,16,8,4,2,1};
vector<int>result(8,0);
    
    for (int i = 0; i < 8; ++i) {
        if (n >= mapping[i]) {
            result[i] = 1;
            n -= mapping[i];
        }
    }
    return result;
}
vector<int> solve(int n){
    vector<int>ans;
    while(n>0){
        ans.push_back(n%2);
        n/=2;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main(){
    int n=10;
    vector<int>ans=decimal_to_binary(n);
    for(auto &ch:ans){
        cout<<ch;
    }
}