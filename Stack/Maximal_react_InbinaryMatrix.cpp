#include<iostream>
#include<vector>
#include<stack>
#include<climits>
using namespace std;

//comcept--> jo hmne lar_rec_histogram wala solve kiiya tha usko hi us krege 
// histogram wale height me hm iss matrix ka col ko add krte jayge

void nextSmallIndex(vector<int>&arr,vector<int>&nextAns){
    stack<int>st;
    int n=arr.size();
    for(int i=n-1;i>=0;i--){
        while(!st.empty()&&arr[st.top()]>=arr[i]){
            st.pop();
        }
        if(st.empty()){
            nextAns[i]=n;
        }
        else{
            nextAns[i]=st.top();
        }
        st.push(i);
    }
}
void prevSmallIndex(vector<int>&arr,vector<int>&prevAns){
    stack<int>st;
    int n=arr.size();
    for(int i=0;i<n;i++){
        while(!st.empty()&&arr[st.top()]>arr[i]){
            st.pop();
        }
        if(st.empty()){
            prevAns[i]=-1;
        }
        else{
            prevAns[i]=st.top();
        }
        st.push(i);
    }
}
int lar_rec(vector<int>&heights){
    vector<int>nextAns(heights.size());
    vector<int>prevAns(heights.size());
     nextSmallIndex(heights,nextAns);
    prevSmallIndex(heights,prevAns);
    int max_area=INT_MIN;
    for(int i=0;i<heights.size();i++){
        int width=nextAns[i]-prevAns[i]-1;
        int hei=heights[i];
        int curr_area=width*hei;
        max_area=max(max_area,curr_area);
    }
    return max_area;
}

int maximalArea(vector<vector<char>>&matrix){
    if(matrix.empty()){
            return 0;
        }
        int maximal_area=0;
        int rows=matrix.size();
        int cols=matrix[0].size();
        vector<int>height(cols,0);
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(matrix[i][j]=='1'){
                    height[j]+=1;
                }else{
                    height[j]=0;
                }
            }
            int area=lar_rec(height);
            maximal_area=max(maximal_area,area);
        }
    return maximal_area;
}
int main(){
    vector<vector<char>>matrix={{'1', '0', '1', '0', '0'},
                                {'1', '0', '1', '1', '1'},
                                {'1', '1', '1', '1', '1'},
                                {'1', '0', '0', '1', '0'}
                                };
    // vector<vector<char>>matrix={{'0'}};
    cout<<maximalArea(matrix);
    return 0;
    
}