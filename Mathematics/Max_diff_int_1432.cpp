#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int getMaximum(int num){
    string s1= to_string(num);
    int idx=s1.find_first_not_of('9');
    if(idx!=string::npos){
        char ch=s1[idx];
        replace(begin(s1),end(s1),ch,'9');

    }
    int new_num=stoi(s1);
    return new_num;
}
int getMinimum(int num){
    string s2=to_string(num);
    //without leading or overall zero 
      for(int i = 0; i < s2.length(); i++) {
            char ch = s2[i];
        if(i == 0) {
            if(ch != '1') {
                replace(begin(s2), end(s2), ch, '1');
                break;
            }
        } else if(ch != '0' && ch != s2[0]) {
            //example : 111, even if we skip 1 at s2[0], we see again at s2[1]
            //But we can't change 1 to 0 because it will replace 1 of s2[0] as well
            replace(begin(s2), end(s2), ch, '0');
            break;
        }
    }
    int new_num=stoi(s2);
    return new_num;
}

//now get to the actual problem
int getMaxDifference(int num){
    int a=getMaximum(num);
    int b=getMinimum(num);
    return (a-b);
}
int main(){
    int num=9;
    cout<<getMaximum(num);
    cout<<endl;
    cout<<getMinimum(num);
    cout<<endl;
    cout<<getMaxDifference(num);
}

