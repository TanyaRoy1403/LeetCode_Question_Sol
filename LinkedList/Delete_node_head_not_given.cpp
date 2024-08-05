#include<iostream>
using namespace std;

/*There is a singly-linked list head and we want to delete a node node in it.

You are given the node to be deleted node. You will not be given access to the first node of head.

All the values of the linked list are unique, and it is guaranteed that the given node node is not the last node in the linked list.

Delete the given node. Note that by deleting the node, we do not mean removing it from memory. We mean:

The value of the given node should not exist in the linked list.
The number of nodes in the linked list should decrease by one.
All the values before node should be in the same order.
All the values after node should be in the same order.*/
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
void solve(Node*node){
    Node* temp = node->next;
    node->data = temp->data;
    node->next = temp->next;
    delete temp;
}
int main(){
    Node* head=NULL;
    insert_beg(9,head);
    insert_beg(1,head);
    insert_beg(5,head);
    insert_beg(4,head);
    Node* tobedel=head->next;
    printll(head);
    solve(tobedel);
    cout<<endl;
    printll(head);


}
