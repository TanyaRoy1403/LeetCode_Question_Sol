#include<iostream>
#include<vector>
using namespace std;

class Node{
  public:
  int data;
  Node* next;
  Node(int value){
    this->data=value;
    this->next=NULL;
  }
};

class Stack{
    public:
    Node* head;
    Stack(){
        this->head=NULL;
    }
    void push(int value){  //insertion at beg
        Node* newNode=new Node(value);

        //empty
        if(head==NULL){
            //sirf newNode hi h
            newNode->next=NULL;
        }
        
        newNode->next=head;
        head=newNode;

    }
    void pop(){  //deletion at beg
        if(head==NULL){
            cout<<"stack is underflow"<<endl;
            return ;
        }
        Node* temp=head;
        head=head->next;
        delete temp;
    }
    int peek(){
        if(head==NULL){
            cout<<"stack has no top"<<endl;
            return -1;
        }
        return head->data;
    }
   void print(){
    //stack empty
    if(head==NULL){
        cout<<"stack is empty"<<endl;
    }
    Node* temp=head;
    while(temp){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
      
   }
};
int main(){
    Stack obj;
    obj.push(10);
    obj.push(20);
    obj.push(30);
    obj.print();
    obj.pop();
    cout<<endl;
    obj.print();
    cout<<endl;
    cout<<obj.peek();

}