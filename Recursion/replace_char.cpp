#include<iostream>
using namespace std;
void replace_char(char arr[],char ele){
    if(arr[0]=='\0'){
        return ;
    }
    if(arr[0]==ele){
        arr[0]='x';
    }
    replace_char(arr+1,ele);
}
int main(){
    char ele;
    cout<<"Enter element to be replace:"<<endl;
    cin>>ele;
    char arr[100]="ababab";
    replace_char(arr,ele);
    cout<<arr;
}

