#include<iostream>
using namespace std;
void remove_char(char arr[],char ele){
    if(arr[0]=='\0'){
        return ;
    }
    if(arr[0]!=ele){
        remove_char(arr+1,ele);
    }
    else{
         for(int i=0;arr[i]!='\0';i++){   ///then we have to shift element towards left
            arr[i]=arr[i+1];
         }
         remove_char(arr,ele);
    }
}
int main(){
    char ele;
    cout<<"Enter element to be replace:"<<endl;
    cin>>ele;
    char arr[100]="ababab";
    remove_char(arr,ele);
    cout<<arr;
}
