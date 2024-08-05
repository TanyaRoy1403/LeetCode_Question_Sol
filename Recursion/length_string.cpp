#include<iostream>
using namespace std;
//int length_str(char arr[]){
//    if(arr[0]=='\0'){
//        return 0;
//    }
//    return 1+length_str(arr+1);
//}
//int main(){
//    char arr[100];
//    cin>>arr;
//    cout<<length_str(arr);
//}

int length_str(string &s,int i){
    if(s[i]=='\0'){
        return 0;
    }
    return 1+length_str(s,i+1);
}
int main(){
    string s;
     getline(cin,s);
    cout<<length_str(s,0);
}
