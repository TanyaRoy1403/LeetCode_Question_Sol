#include<iostream>
#include<string>
using namespace std;
/*A password is said to be strong if it satisfies all the following criteria:

It has at least 8 characters.
It contains at least one lowercase letter.
It contains at least one uppercase letter.
It contains at least one digit.
It contains at least one special character. The special characters are the characters in the following string: "!@#$%^&*()-+".
It does not contain 2 of the same character in adjacent positions (i.e., "aab" violates this condition, but "aba" does not).
Given a string password, return true if it is a strong password. Otherwise, return false.*/

bool strongPasswordChecker_II(string password) {
        int lower_case=0;
        int upp_case=0;
        int digit_count=0;
        int special_count=0;
        string special_chars="!@#$%^&*()-+";
        bool adj_char=false;
        if(password.length()<8){
            return false;
        }
        for(int i=0;i<password.length();i++){
            if(password[i]>='a'&&password[i]<='z') {
                lower_case++;
                }
            else if(password[i]>='A'&&password[i]<='Z'){
                upp_case++;
            }
            else if(password[i]>='0'&&password[i]<='9'){
                digit_count++;
            }
            else if(special_chars.find(password[i])!=string::npos){
                special_count++;
            }
            if(i>0 &&password[i]==password[i-1]){
                adj_char=true;
            }
        }
            if((lower_case>=1)&&(upp_case>=1)&&(digit_count>=1)&&(special_count>=1)&&(!adj_char)){
                return true;

        }
        return false;
        
}
/*-----Time complexity:O(n)------
     Space complexity:O(1)-------*/
//*optimal sol -->we can only reduce over type code
bool strongPasswordCheckerII(string password) {
        int lower_case=0;
        int upp_case=0;
        int digit_count=0;
        int special_count=0;
        string special_chars="!@#$%^&*()-+";
        bool adj_char=false;
        if(password.length()<8){
            return false;
        }
        for(int i=0;i<password.length();i++){
            if(islower(password[i])) {
                lower_case++;
                }
            else if(isupper(password[i])){
                upp_case++;
            }
            else if(isdigit(password[i])){
                digit_count++;
            }
            else if(special_chars.find(password[i])!=string::npos){
                special_count++;
            }
            if(i>0 &&password[i]==password[i-1]){
                adj_char=true;
            }
        }
            if((lower_case>=1)&&(upp_case>=1)&&(digit_count>=1)&&(special_count>=1)&&(!adj_char)){
                return true;

        }
        return false;
        
}


int main(){
    string password="Me+You--IsMyDream";
   bool rsult=strongPasswordCheckerII(password);
   if(rsult){
    cout<<"passwor is strong:"<<endl;
   }
   else{
    cout<<"password is not strong"<<endl;
   }

}