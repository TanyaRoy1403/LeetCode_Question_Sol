#include<iostream>
using namespace std;

class Node{
    public:
    Node* prev;
    int data;
    Node* next;
    Node(int value){
        this->prev=NULL;
        this->data=value;
        this->next=NULL;
    }

};


//^insertion at beg
Node* insert_beg(int value,Node*& head){
    Node* newNode=new Node(value);
    //empty
    if(head==NULL){
        head=newNode;
    }else{
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
    }
    return head;
}
//*insertion at end
Node* insert_end(int value,Node*& head){
    Node* newNode=new Node(value);
    //empty 
    if(head==NULL){
        head=newNode;
    }else{
        Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
        newNode->prev=temp;

    }
    return head;
}
//*insertion after value
Node* insert_after_val(int value,int data,Node*& head){
    Node* newNode=new Node(data);
    //empty
    if(head==NULL){
        head=newNode;
    }else{
        Node* temp=head;
        while(temp!=NULL&&temp->data!=value){
            temp=temp->next;
        }
        //&value not found
        if(temp==NULL){
            cout<<"value not found"<<endl;
            return head;
        }
        //& if found and temp last node nhi h to newNode ka next ko tmep->next se link
        newNode->next=temp->next;
        newNode->prev=temp;
        if(temp->next!=NULL){  //& agr temp se ek aage wala node v present hoga to uska prev ko newNode ke next se link
            temp->next->prev=newNode;
        }
        temp->next=newNode; //&agr temp se aage node hi nhi h to sirf temp ka next ko newNode se link
        
    }
    return head;
}
//&length function
int getLength(Node* head) {
  int len = 0;
  Node* temp = head;

  while(temp != NULL) {
    temp = temp->next;
    len++;
  }
  return len;
}
//*Insertion at index
Node* insert_idx(int value,int pos,Node*& head){
    int length=getLength(head);
    Node* newNode=new Node(value);
    if(head==NULL){
        head=newNode;
    }
    else{
        //&only one node and pos==1
        if(pos==1){
            insert_beg(value,head);
        }else if(pos==length+1){
            insert_end(value,head);
        }else{
            Node* temp=head;
            for(int i=0;i<pos-2;i++){
                temp=temp->next;
            }
        Node* forward=temp->next;
        newNode->prev = temp;
        temp->next = newNode;
        forward->prev = newNode;
        newNode->next = forward;
        }
    }
    return head;
    
}
//^reversing dll using iteration
Node* reverseDLL(Node * head)
    {
        //Your code here
    Node* current = head;
    Node* temp = NULL;
    
    // Traverse the list and swap next and prev pointers
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    
    // Before changing the head, check for the cases like empty list
    // and list with only one node
    if (temp != NULL) {
        head = temp->prev;
    }
    
    return head;
    }
//^print function

void printll(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
}
int main(){
    Node* head=NULL;
    insert_beg(10,head);
    insert_beg(20,head);
    insert_end(60,head);
    insert_end(100,head);
    insert_after_val(60,57,head);
    insert_idx(900,3,head);
    insert_idx(890,1,head);
    head=reverseDLL(head);
    printll(head);

}