#include<iostream>
#include<vector>
#include<stack>
using namespace std;

//implemantation of stack of using arr
// class Stack{

//     public:
//     int *arr;  //pointer to create array dynamically
//     int size;
//     int top;

//     //constructor
//      Stack(int capacity){
//         arr=new int[capacity];
//         this->size=capacity;
//         top=-1;
//      }
//      bool isEmpty(){
//         if(top==-1){
//             return true;
//         }
//         return false;
//      }
//      void pop(){
//         if(top==-1){
//             cout<<"stack is empty";
//         }else{

//             arr[top]=-1;
//             top--;
//         }

//      }
//      void push(int value){
//         if(top==size-1){
//             cout<<"stack is full";
//         }else{
//             top++;
//             arr[top]=value;
//         }

//      }
//      int getTop(){
//         //empyt
//         if(top==-1){
//             cout<<"no top"<<endl;
//         }
//         return arr[top];
//      }
//      int getSize(){
//         return top+1;

//      }
// };

//implementation of two stack using arr

class Stack {
public:
    int *arr;
    int top1;
    int top2;
    int size;

    Stack(int capacity) {
        arr = new int[capacity];
        size = capacity;
        top1 = -1;
        top2 = size;
    }

    void push1(int value) {
        // overflow
        if (top2 - top1 <= 1) {
            cout << "stack is overflow" << endl;
        } else {
            top1++;
            arr[top1] = value;
        }
    }

    void push2(int value) {
        // overflow
        if (top2 - top1 <= 1) {
            cout << "stack is overflow" << endl;
        } else {
            top2--;
            arr[top2] = value;
        }
    }

    void pop1() {
        // underflow
        if (top1 == -1) {
            cout << "stack is underflow" << endl;
        } else {
            arr[top1] = 0;
            top1--;
        }
    }

    void pop2() {
        // underflow
        if (top2 == size) {
            cout << "stack is underflow" << endl;
        } else {
            arr[top2] = 0;
            top2++;
        }
    }

    void print() {
        cout << "Top1: " << top1 << endl;
        cout << "Top2: " << top2 << endl;
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void insertAtBottom(stack<int>& s, int value) {
  //base case
  if(s.empty()) {
    s.push(value);
    return;
  }
  //1 case hum krenge and baaki recursion karega
  int topElement = s.top();
  s.pop();

  //baaki recursion
  insertAtBottom(s,value);

  //backtrack
  s.push(topElement);
}

int main() {
    Stack s(5);
    s.push1(10);
    s.print();
    s.push2(90);
    s.print();
    s.push2(80);
    s.print();
    s.pop1();
    s.print();
    s.push2(90);
    s.print();
    s.push2(80);
    s.print();
    s.push2(80); // This will cause overflow
    s.print();
    s.push1(80); // This will cause overflow
    s.print();
    return 0;
}
