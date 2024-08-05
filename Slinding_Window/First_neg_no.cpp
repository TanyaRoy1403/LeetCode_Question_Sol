#include<iostream>
#include<vector>
using namespace std;

//!Brute force

vector<int> first_neg(vector<int>&arr,int k){
    int n=arr.size();
    vector<int>ans;
    for(int i=0;i<=n-k;i++){
        bool found=false;
        for(int j=i;j<i+k;j++){
            if(arr[j]<0){
                ans.push_back(arr[j]);
                found=true;
                break;
            }
        }
  
        if(!found){
        ans.push_back(0);
        }
    }
    return ans;
}
//^slinding window

vector<int> first_ne_2(vector<int>&arr,int k){
    int n=arr.size();
    int i=0;
    int j=0;
    vector<int>ans;  //^store krega current ele agr negative nikal gya or window size k ke equal nhi h
    vector<int>final_result;  //^yeh final ans store gyega jaha phela negativ mila or window size v k ke equal h
    while(j<n){
        if(arr[j]<0){  //*current ele ko check krega 
            ans.push_back(arr[j]);
        }
        if(j-i+1<k){
            j++;
        }else if(j-i+1==k){   //* size hit gya to jo ans ke front me hoga wohi phela neagtive hoga iss window ke liye
              if(ans.size()==0){
                final_result.push_back(0);
            }else{
                final_result.push_back(ans.front());
                  if(arr[i]<0){
                     ans.erase(ans.begin());
                  }
            }
            i++;
            j++;
    
        }
   
    }
    return final_result;
}
int main(){
    vector<int>arr= {12, -1, -7, 8, -15, 30, 16, 28};
    int k=3;
    vector<int>ans=first_ne_2(arr,k);
    for(auto &ch:ans){
        cout<<ch<<" ";
    }
}