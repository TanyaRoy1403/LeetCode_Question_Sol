#include<iostream>
#include<vector>
#include<set>
using namespace std;

int solve(vector<vector<int>>&arr){
    set<int>st;
    int n=arr.size();
    int count=0;
    // for(int i=0;i<n;i++){
    //     int start=arr[i][0];
    //     int end=arr[i][1];
    //      cout << "Start: " << start << ", End: " << end << endl;
    // }
    for(auto &ch:arr){
        int start=ch[0];
        int end=ch[1];
       
        for (int j = start; j <= end; j++) {

            st.insert(j);
        }
    }
    return st.size();
}
int main(){
    vector<vector<int>>arr={{1,3},{5,8}};
    cout<<solve(arr);
    
}