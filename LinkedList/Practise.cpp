#include<iostream>
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
Node* insert_beg(int value ,Node*& head){ 
    Node* newNode=new Node(value);
    //ll empty
    if(head==NULL){
        head=newNode;
    }else{
        newNode->next=head;
        head=newNode;
    }
    return head;
}

void printll(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
}
Node* delete_beg(Node*& head){
    if(head==NULL){
        return head;
    }
    if(head->next==NULL){
        delete head;
        head=NULL;
    }
    else{
        Node* temp=head;
        head=head->next;
        delete temp;


    }
    return head;

}
int main(){
    Node* head=NULL;
    insert_beg(90,head);
    insert_beg(80,head);
    insert_beg(70,head);
    insert_beg(60,head);
    printll(head);
    cout<<endl;
    delete_beg(head);
    delete_beg(head);
    printll(head);
}