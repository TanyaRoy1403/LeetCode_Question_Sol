#include<iostream>
#include<string>
#include<vector>
using namespace std;

/*spit function will break string into specific order ---or we can say after specific delimeter  ,,split(string_name,dleimeter_name)*/

vector<string> split(string &word,char delimeter){

    vector<string>result;
    string currWord;

    for(auto &ch:word){
        if(ch==delimeter){
            result.push_back(currWord);
            currWord.clear();
        }else{
            currWord.push_back(ch);
        }
    }
    result.push_back(currWord);   //^last wala char ko last me insert kr kr deyge
    return result;
}
// int main(){
//     string word="hello.world.tanya.roy";
//     vector<string>ans=split(word,'.');
//     for(auto &ch:ans){
//         cout<<ch<<endl;
//     }
// }