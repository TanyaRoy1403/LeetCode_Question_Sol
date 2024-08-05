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

Node* insert_end(int value,Node*& head){
        Node* newNode=new Node(value);
        if(head==NULL){
            head=newNode;
        }else{
            Node* temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newNode;
            newNode->next=NULL;
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

Node* find_mid(Node* &head){
    Node* slow=head;
    Node* fast=head;
    //empty
    if(head==NULL){
        return head;
    }
    else{
        while(fast!=NULL &&fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }

    }
    return slow;
}
int main(){
    Node* head=NULL;
    insert_end(1,head);
    insert_end(2,head);
    insert_end(3,head);
    insert_end(4,head);
    insert_end(5,head);
    insert_end(6,head);
    find_mid(head);
}