
#include<iostream>
using namespace std;

/*Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.*/

class Node{
    public:
    //^attributes
    int data;
    Node* next;

    //^constructor
    Node(int value){
        this->data=value;
        this ->next=NULL;
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

Node* partion_ll(Node*& head,int x){
    if(head==NULL){
        return head;
    }
    Node* curr=head;
    Node* smallDumy=new Node(0);
    Node* temp1=smallDumy;
    Node* largeDumm=new Node(0);
    Node* temp2=largeDumm;
    while(curr){
        if(curr->data<x){
            temp1->next=curr;
            temp1=temp1->next;
        }
        else{
            temp2->next=curr;
            temp2=temp2->next;
        }
        curr=curr->next;
    }
    temp2->next=NULL;
    temp1->next=largeDumm->next;

    Node* newHead = smallDumy->next; // The new head of the partitioned list
    
    delete smallDumy; // Clean up the dummy nodes
    delete largeDumm;
    return newHead;
}
int main(){
    Node* head=NULL;
    insert_end(1,head);
    insert_end(4,head);
    insert_end(3,head);
    insert_end(2,head);
    insert_end(5,head);
    insert_end(2,head);
    Node* newHead=partion_ll(head,3);
    printll(newHead);
}