#include<iostream>
#include<string>
using namespace std;
int solve(string s){
    int diff=0;
    for(int i=0;i<s.length()-1;i+=2){
         diff += abs(s[i]-s[i+1]);
    }
    return diff;
}
int main(){
    string s="hello";
    // string s1="h e l l o";  //^ space is also consider as a char , first remove space
    cout<<solve(s)<<endl;
    
}

/*---------------------------------------fun to remove space-----------------------------------------------------*/
   // string removeSpaces(string s) {
    //     s.erase(remove(s.begin(), s.end(), ' '), s.end());
    //     return s;
    // }
/*----------------------------------------------------------------------------------------------------------------*/
