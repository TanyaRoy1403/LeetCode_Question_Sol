#include<iostream>
#include<string>
#include<vector>
using namespace std;
//int occ(int arr[],int n,int x){
//
//    int count=0;
//    for(int i=0;i<n;i++){
//        if(arr[i]==x){
//            count+=1;
//        }
//    }
//    return count;
//}
/////recursion
//int count_occ(int arr[],int n,int ele,int i){
//    if(i==n){
//        return 0;
//    }
//    if(arr[i]==ele){
//        return 1+count_occ(arr,n,ele,i+1);
//    }
//    else{
//        return 0+count_occ(arr,n,ele,i+1);
//    }
//}
//int main(){
//    int arr[]={5,5,6,5,6};
//    cout<<occ(arr,5,6);
//    cout<<endl;
//    cout<<count_occ(arr,5,5,0);
//    string s="tanya";
//    int in=s[1];
//    cout<<in;
//
//}


//int main() {
//    // Declare a 2D vector
//    vector<int>ans;
//
//    // Add rows to the 2D vector
//    ans.push_back(vector<int>{1, 2, 3});
//    ans.push_back(vector<int>{4, 5, 6});
//    ans.push_back(vector<int>{7, 8, 9});
//
//    // Accessing elements in the 2D vector
//    for (int i = 0; i < ans.size(); ++i) {
//        for (int j = 0; j < ans[i].size(); ++j) {
//            cout << ans[i][j] << " ";
//        }
//        cout << endl;
//    }
//
//    return 0;
//}
bool check_alpha(char ch){
    if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    char ch='M';
    bool result=check_alpha(ch);
    if(result){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }


}
