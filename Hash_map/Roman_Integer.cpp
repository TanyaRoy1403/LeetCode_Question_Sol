#include<iostream>
#include<unordered_map>
using namespace std;

//using switch 

int getInteger(char c) {
    switch (c) {
        case 'I' : return 1;
        case 'V' : return 5;
        case 'X' : return 10;
        case 'L' : return 50;
        case 'C' : return 100;
        case 'D' : return 500;
        case 'M' : return 1000;
        default : return -1;
    }
}

int romanToInt(string s) {
    int result = 0;
    for (int i = 0; i < s.length(); ++i) {
        int current = getInteger(s[i]);
        int next = (i + 1 < s.length()) ? getInteger(s[i + 1]) : 0;
        if (current < next) 
            result -= current;
         else {
            result += current;
        }
    }
    
 return result;
}
//using map
int getInt(string s){
    unordered_map<char,int>mp={
        {'I',1},{'V',5},{'X',10},{'C',50},{'L',100},{'D',500},{'M',1000}
    };
    int total=0;
    for(int i=0;i<s.length();i++){
        if(i+1<s.length()&&mp[s[i]]<mp[s[i+1]]){
            total-=mp[s[i]];
        }else{
            total+=mp[s[i]];
        }
    }
    return total;
}
int main(){
    string s="MMD";
    cout<<"using switch:"<<" ";
    cout<<romanToInt(s);
    cout<<endl;
    cout<<"using map:"<<" ";
    cout<<getInt(s);

}
    
