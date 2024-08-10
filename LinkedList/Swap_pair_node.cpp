#include<iostream>
using namespace std;
/*Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the 
list's nodes (i.e., only nodes themselves may be changed.)*/

class Node{
    public:
    int data;
    Node* next;
    Node(int value){
        this->data=value;
        this->next=NULL;
    }
};
void printll(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
}
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

Node* swapPairs(Node*& head){
           //empty ya ek node
        if(head==NULL|| head->next==NULL){
            return head;
        }
        //A=head
        //B=head->next
        //C=head->next->next
        Node* temp=head->next;
        head->next=swapPairs(head->next->next);  // A ko baaki aage wale swapped(jo recursion kr diya h) uses link kr rhe h
        temp->next=head; // B ko head bna rhe h
        return temp;
}
int main(){
    Node* head=NULL;
    insert_end(1,head);
    insert_end(2,head);
    insert_end(3,head);
    insert_end(4,head);
    Node* newHead=swapPairs(head);
    printll(newHead);
}
