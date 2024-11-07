#include<iostream>
#include<vector>
#include<stack>
using namespace std;

/**/

vector<int> asteroidCollision(vector<int>&arr){
    stack<int>st;
    for(int i=0;i<arr.size();i++){
        int curr_ele=arr[i];
        while(!st.empty()&& st.top()>0 && curr_ele<0){
            int sum=st.top()+curr_ele;
            if(sum<0){
                //mtlb  curr_ele jo h top wale bda h ,iska mtlb top wale ko destroy krna hoga
                st.pop();
            }else if(sum>0){
                //mtlb curr_ele ho h woh bda nhi, mtlb top wala bda h ,mtlb curr_ele ko destroy krna hoga
                curr_ele=0; //replace kr diye koi v vlaue se kr skte the
            }else{
                //sum==0
                //mtlb dono ko destroy krna hoga
                curr_ele=0;
                st.pop();
            }

        }
        if(curr_ele!=0){
            st.push(curr_ele);
        }
    }
    //ab stack se nikalege
    //reverse krne se acha yeh kro
    int n=st.size();
    vector<int>ans(n);
    int i=n-1;
    while(i>=0){
        ans[i]=st.top();
        st.pop();
        i--;
    }
        return ans;
}
int main(){
    vector<int>arr={8,-8};
    vector<int>ans=asteroidCollision(arr);
    for(auto &ch:ans){
        cout<<ch<<" ";
    }
    return 0;
}