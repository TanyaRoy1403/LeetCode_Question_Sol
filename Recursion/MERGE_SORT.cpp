#include<iostream>
#include<vector>
using namespace std;

vector<int> break_arr(vector<int>&arr,int s ,int e ){
    int mid=s+(e-s)/2;
    int len_left_arr=mid-s+1;
    int len_right_arr=e-mid;
    vector<int>left_arr(len_left_arr);
    vector<int>right_arr(len_right_arr);

    //^left arrya me copy
    int indx=s;  //main array ka index
    for(int i=0;i<len_left_arr;i++){
        left_arr[i]=arr[indx];
        indx++;
    }
    //^right array me copy
    indx=mid+1;
    for(int i=0;i<len_right_arr;i++){
        right_arr[i]=arr[indx];
        indx++;
    }

    //merge
    // vector<int>final_arr;
    int i=0; //left_arr ka index
    int j=0; //rigth_arr ka index
    int k=0;  //final_arr ka index
    while(i<len_left_arr &&j<len_right_arr){
        if(left_arr[i]<right_arr[j]){
            arr[k]=left_arr[i];
            i++;
            k++;
        }else{
            arr[k]=right_arr[j];
            j++;
            k++;

        }
     }

     //jb dono me se (left_arr,right_arr) me kisi me v ele rh gya to sidha copy kr do final_arr me
    while(i<len_left_arr){
        arr[k]=left_arr[i];
        i++;
        k++;
    }
    while(j<len_right_arr){
        arr[k]=right_arr[j];
        j++;
        k++;
    }
     return arr;

}
int main(){
    vector<int>arr={10,80,110,90,50,30,40,20};
    vector<int>ans=break_arr(arr,0,7);
    for(auto &ch:ans){
        cout<<ch<<" ";
    }

}