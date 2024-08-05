#include<iostream>
using namespace std;

/*You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.

The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, 
where ⌊x⌋ denotes the largest integer less than or equal to x.

For n = 1, 2, 3, 4, and 5, the middle nodes are 0, 1, 1, 2, and 2, respectively.*/

class Node{

    public:
    int data;
    Node* next;

    Node(int value){
        this->data=value;
        this->next=NULL;
    }
};

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
/*//&------------------------------------------Delete middle node-------------------------------------------------------------------*/
Node* delete_mid(Node*& head){
    int length=getLength(head);
    int mid_pos=length/2;
    if(head==NULL){
        cout<<"deletion not possible";
        return head;
    }
    if(mid_pos==0){
        delete head;
        head=NULL;
    }else{
        Node* temp=head;
        for(int i=0;i<mid_pos-1;i++){
            temp=temp->next;
        }
        Node* midNode=temp->next; //^temp hmne mana h usko jo just mid se ek phele hoga
        temp->next=midNode->next;
        delete midNode;
    }
    return head;
}
/*-----------------------------------------------------------------------------------------------------------------------------------*/

Node* delete_mid2(Node*head){
    Node* slow=head;
    Node* fast=head;
    Node* pre=NULL;
    while(fast!=NULL&& fast->next!=NULL){
        pre=slow;
        slow=slow->next;
        fast=fast->next->next;
    }
    if(pre == NULL) {
            return NULL;
        }
        
    pre->next = slow->next;
        delete(slow);
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
int main(){
    Node* head=NULL;
    insert_beg(6,head);
    insert_beg(2,head);
    insert_beg(1,head);
    insert_beg(7,head);
    insert_beg(4,head);
    insert_beg(3,head);
    insert_beg(1,head);
    delete_mid2(head);
    printll(head);
}