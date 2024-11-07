#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;
class BrowserHistory {
public:
   
    stack<string>bkwStack;
    stack<string>fwdStack;
    BrowserHistory(string homepage) {
        bkwStack.push(homepage);
    }
    
    void visit(string url) {
        while(!fwdStack.empty())
            fwdStack.pop();
        bkwStack.push(url);   
    }
    
    string back(int steps) {
        while(steps--){
            if(bkwStack.size()>1){
            fwdStack.push(bkwStack.top());
            bkwStack.pop();
            }
            else{
                break;
            }
        }
     return bkwStack.top();
        
    }
    
    string forward(int steps) {
        while(steps--){
            if(!fwdStack.empty()){
                bkwStack.push(fwdStack.top());
                fwdStack.pop();
            }
        }
        return bkwStack.top();
    }
};

int main(){
  string homepage;
  BrowserHistory* obj = new BrowserHistory(homepage);
  string url;
  obj->visit(url);
  int steps;
  string param_2 = obj->back(steps);
  string param_3 = obj->forward(steps);
}
 
 