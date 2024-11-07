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
int binaryToDecimal(vector<int>& arr) {
    int result = 0;
    int base = 1; // 2^0 initially
    for (int i = arr.size() - 1; i >= 0; i--) {
        result += arr[i] * base;
        base *= 2; // Move to the next power of 2
    }
        return result;
}
int main(){
    int n=10;
    vector<int>ans=decimal_to_binary(n);
    for(auto &ch:ans){
        cout<<ch;
    }
    cout<<endl;
    cout<<binaryToDecimal(ans);
    return 0;
}