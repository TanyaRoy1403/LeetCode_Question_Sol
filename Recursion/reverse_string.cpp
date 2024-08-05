#include<iostream>
#include<math.h>
using namespace std;
//void print(char arr[]){
//    if(arr[0]=='\0'){
//        return ;
//    }
//    cout<<arr[0]<<endl;
//    print(arr+1);
//}
//void print_reverse(char arr[]){
//    if(arr[0]=='\0'){
//        return ;
//    }
//    print(arr+1);
//    cout<<arr[0]<<endl;
//}
//int main(){
//    char arr[100]="roy";
//    print(arr);
//    cout<<endl;
//    print_reverse(arr);
//}


//void print(string s){
//    if(s[0]=='\0'){
//        return ;
//    }
//    cout<<s[0]<<endl;
//    print(s.substr(1));   ///slice the substring -->substr(start_index,last_in)
//}
//void print_reverse(string s){
//    if(s[0]=='\0'){
//        return ;
//    }
//    print(s.substr(1));
//    cout<<s[0]<<endl;
//}
//int main(){
//    string s="roy";
//    print(s);
//    cout<<endl;
//    print_reverse(s);
//}


void print_rev(char arr[],int s,int e){
    if(s>e){
        return;
    }
    swap(arr[s],arr[e]);
    print_rev(arr,s+1,e-1);
}
int main(){
    char arr[100]="1231";
    int s=0;
    int e=3;
    print_rev(arr,s,e);
    cout<<arr<<" ";
}
