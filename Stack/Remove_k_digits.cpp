#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
/*Given string num representing a non-negative integer num, and an integer k, 
return the smallest possible integer after removing k digits from num.*/

string removeKdigits(string s,int k){
    stack<char>st;
    string result="";
    if(s.length()==k){
        return "0";
    }
    for(auto &ch:s){
        while(!st.empty()&&st.top()>ch&&k>0){
            st.pop();
            k--;
        }
        st.push(ch);
    }
    //itna krne ke baad v agr k 0 nhi hua to fir se pop kro
    while(k>0&&!st.empty()){
        st.pop();
        k--;
    }
    while(!st.empty()){
        result.push_back(st.top());
        st.pop();
    }
    //reverse krne se phle piche wale zero ko hta do(stack ke top) jo reverse hone ke badd startig or the result me hoga(leading zero)
    //remove trailing zero
    while(result.size()>0 && result.back()=='0'){
        result.pop_back();
    }
    std::reverse(result.begin(),result.end());

    if(result.empty()) {
        return "0";
    }
    return result;
}
int main(){
    string s="000";
    int k=1;
    cout<<removeKdigits(s,k);
    return 0;
}