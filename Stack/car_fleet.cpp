#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

int car_fleet(vector<int>&position,vector<int>&speed,int target){
    stack<float>st;
    vector<pair<int,float>>vec;
    int n=position.size();
    for(int i=0;i<n;i++){
        float time=(float)(target-position[i])/speed[i];
        vec.push_back({position[i],time});
    }
    sort(vec.rbegin(),vec.rend());
    for(auto &ch:vec){
        float time=ch.second;
        if(st.empty()||time>st.top()){
            st.push(time);
        }
    
    }
return st.size();
}
int main(){
    vector<int>position={3};
    vector<int>speed={3};
    int target=10;
    cout<<car_fleet(position,speed,target);
    return 0;
}