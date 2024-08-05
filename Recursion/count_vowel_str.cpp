#include<bits/stdc++.h>
using namespace std;
char toLower(char ch){
    if(ch>='a'&&ch<='z'){
        return ch;
    }
    else{
        char temp=ch-'A'+'a';   ///toUpper-->ch-'a'+'A'
          return temp;
    }
}
int count_vowel(vector<char>&s){
    int count=0;
    for(char ch:s) {    ///for every char in s
        ch=toLower(ch);
      if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            count++;
        }

    }
    return count;

}

int main(){
//    string s="tanyaaa";
    cout<<"enter length:";
    int n;
    cin>>n;
    vector<char>s(n);
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    cout<<"number of vowels:"<<count_vowel(s)<<endl;
//    cout<<count_vowel(s)<<endl;



}





