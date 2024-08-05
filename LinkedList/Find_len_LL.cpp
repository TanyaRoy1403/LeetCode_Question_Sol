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

Node*  insert_beg(int value,Node*& head){
        Node* new_node= new Node(value);
        
        //*if ll empty
        if(head==NULL){
            head=new_node;
        }else{
           
            new_node->next=head;
            head=new_node;
        }
        return head;
    }
int len_ll(Node* head){
    Node* temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}
int main(){
    Node* head=NULL;
    insert_beg(10,head);
    insert_beg(20,head);
    insert_beg(30,head);
    insert_beg(40,head);
    int res=len_ll(head);
    cout<<res;
}