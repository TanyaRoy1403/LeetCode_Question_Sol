#include<bits/stdc++.h>
using namespace std;
int mini_move(vector<int>&arr){
    sort(arr.begin(),arr.end());
    int move=0;
    for(int i=1;i<arr.size();i++){
        if(arr[i-1]>=arr[i]){
            move+=arr[i-1]-arr[i]+1;
            arr[i]=arr[i-1]+1;  ///increment current ele by one of its previous value ele;
        }
    }
    return move;
}
///using count array
int mini_moove2(vector<int>&arr){
    int move=0;
    int max_value=0;
    for(auto &it:arr){
        max_value=max(max_value,it);
    }
    int max_len=max_value+arr.size();
    vector<int>count_arr(max_len+1,0);
    for(auto &it:arr){
        count_arr[it]++;
    }
    for(int i=0;i<max_len;i++){
        if(count_arr[i]>1){
            int extra_fre=count_arr[i]-1;
            count_arr[i+1]+=extra_fre;  ///move forward
            count_arr[i]=1;  ///current ele ka fre ko 1 kr diye baaki extra ko aage bej diye
            move+=extra_fre;
        }
    }
    return move;
}
int main(){
    vector<int>arr={1,2,2};
    cout<<mini_moove2(arr);
    cout<<endl;
    cout<<mini_move(arr);

}
