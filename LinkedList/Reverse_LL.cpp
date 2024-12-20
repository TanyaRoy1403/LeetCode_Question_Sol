#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int value){
        this->data=value;
        next=NULL;
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

//method:1 iterative

Node* reverseLL(Node* head){
    if(head==NULL){
        return head;
    }
    Node* prev=NULL;
    while(head){
        Node* headkanext=head->next;
        head->next=prev;
        prev=head;
        head=headkanext;
    }
    return prev; //last wala head bn jayega n
}
//method2: recursion

Node* rvell(Node* head){
    //base case
    if(!head || head->next==NULL){
        return head;
    }
    Node* lastnodekonh= rvell(head->next);

    //ab us last node ko head bna do
    head->next->next=head;
    head->next=NULL;
    return lastnodekonh;
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
    insert_end(1,head);
    insert_end(2,head);
    insert_end(3,head);
  
    head=reverseLL(head);
    printll(head);
    cout<<endl;
    head=rvell(head);
    printll(head);
    return 0;

}