#include<iostream>
#include<vector>
using namespace std;
/* find quetiont when dividend divided by divisor. wihtout using '/'and '%' operator*/
int find_que(int dividend ,int divisor){
    int s=0;
    int e=dividend;
    int ans=-1;
    while(s<=e){
        int mid=s+((e-s)>>1);
        if((divisor*mid)==dividend){
             return mid;
        }else if((divisor*mid)<dividend){
            ans=mid;
            s=mid+1;
        }else{
            e=mid-1;
        }
    }
    return ans;
}
int main(){
    int dividend=-2147483648;
    int divisor=-1;
    int ans=find_que(abs(dividend),abs(divisor)) ; //to handle negative divisor
    if((dividend<0)&& (divisor>0)||(dividend>0)&& (divisor<0)){
        ans=0-ans;
    }
    cout<<"Final ans:"<<ans;

}