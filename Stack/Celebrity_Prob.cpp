#include<iostream>
#include<vector>
#include<stack>
using namespace std;

/*-------------------------------------------------Brute force---------------------------------*/

bool isKnows(int a,int b,vector<vector<int>>&arr){
    //condition to know
    if(arr[a][b]==1){ // a janta h b ko but b nhi janta h a ko
        return true;
    }
    return false;
}

int cleb_find(vector<vector<int>>&arr){
    //traverse the matrix
    int n=arr.size();
    int m=arr[0].size();
    for(int i=0;i<n;i++){
        bool isCleb=true; //maan lete h ki phela wala hi cleb h
        for(int j=0;j<m;j++){
            if(i!=j){  //equal wala ke matlb khude ko khude se jana jo ki question me 0 diya h (diagonal of matrix)
            //jo v cleb hoga woh ith row me hoga
              if(isKnows(i,j,arr)|| !isKnows(j,i,arr)){  //i j ko janta h but j i ko nhi janta h --> i kv v cleb nhi hoga
                    isCleb=false;
                    break;
              }

            }
        }
        if(isCleb){
            return i; //uska row
        }
    }
    return -1;
}
/*----------------------------------optimal solution (stack)-----------------------------------------------------------*/
int cele_find(vector<vector<int>>&arr){
    stack<int>st;
    int n=arr.size();
    for(int i=n-1;i>=0;i--){
        st.push(i);
    }
    while(st.size()>1){
        int first=st.top();
        st.pop();
        int second=st.top(); 
        st.pop();
        if(isKnows(first,second,arr)){
            st.push(second); //first sec ko janta h mtbl first celeb nhi hoga
        }else{
            st.push(first);
        }
    }
    int finalTop=st.top();
    //verify kro ki ye hi celeb h ki nhi
    //condition, isi finalTop ke row ka sum 0 hoga and col ka sum=n-1 hoa tb hi celeb hoga yeh

/*-----------------------------itna ke jgh (verification) yeh v kr skte the-----------------------------*/
//   for (int i = 0; i < n; i++) {
//         if (i != finalTop) {
//             if (isknow(finalTop, i, arr) || !isknow(i, finalTop, arr)) {
//                 return -1; // Not a celebrity
//             }
//         }
//     }

//     return finalTop;
/*------------------------------------------------------------------------------------------------------------------*/

    int rowSum=0,Colsum=0;
    for(int i=0;i<n;i++){
        rowSum+=arr[finalTop][i]; //row to same h but col change ho rha h
        Colsum+=arr[i][finalTop];//col to same h row change ho rha h
    }
   if(rowSum==0&&Colsum==n-1){
    return finalTop;
   }
   return -1;
}
int main(){
    vector<vector<int>>arr={{0,1},{1,0}};
    cout<<cleb_find(arr);
    cout<<endl;
    cout<<cele_find(arr);
}