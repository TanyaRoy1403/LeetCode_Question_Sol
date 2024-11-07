#include<iostream>
#include<vector>
using namespace std;

class MinStack {
public:
    vector<pair<int,int>>v; //pair.first->curr ele, pair.second-> min till now
    MinStack() {
        
    }
    
    void push(int val) {
        //empty
        if(v.empty()){
            v.push_back({val,val});
            return;
        }
        int min=val; //min ele till now
        if(v.back().second<min) //last pair ka second wala chota h
        min=v.back().second;
        v.push_back({val,min}); 
    }
    
    void pop() {
        //empty
        if(v.empty()){
            return;
        }
        v.pop_back();
        
    }
    
    int top() {
        //empty
        // if(v.empty()){
        //     return -1;
        // }
        return v.back().first;
        
    }
    
    int getMin() {
        return v.back().second;
        
    }
};
int main(){
    MinStack* obj=new MinStack;
     obj->push(-2);
    obj->push(0);
    obj->push(3);
    cout << "Minimum: " << obj->getMin() << endl; // Should print -2
    obj->pop();
    cout << "Top: " << obj->top() << endl; // Should print 0
    cout << "Minimum: " << obj->getMin() << endl; // Should print -2

    delete obj; // Cleanup dynamic memory
    return 0;
}