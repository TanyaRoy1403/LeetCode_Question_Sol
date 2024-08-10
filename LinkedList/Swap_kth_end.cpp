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
int getLength(Node* head) {
  int len = 0;
  Node* temp = head;

  while(temp != NULL) {
    temp = temp->next;
    len++;
  }
  return len;
}

Node* slove(Node*& head,int k){
    int len=getLength(head);
    if(head==NULL){
        return head;
    }
    Node* prev=head;
    Node* second=head;
    for(int i=1;i<k;i++){
        prev=prev->next;
    }
    for(int i=0;i<len-k;i++){
        second=second->next;
    }
     if (prev != NULL && second != NULL) {
        int tempData = prev->data;
        prev->data = second->data;
        second->data = tempData;
    }
  
    return head;
}
int main(){
    Node* head=NULL;
    insert_end(5,head);
    insert_end(10,head);
    insert_end(8,head);
    insert_end(5,head);
    insert_end(9,head);
    insert_end(3,head);
    int k=2;
    slove(head,k);
    printll(head);
}