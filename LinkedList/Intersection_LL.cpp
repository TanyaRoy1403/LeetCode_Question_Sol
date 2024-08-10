#include<iostream>
#include<unordered_map>
using namespace std;

/*Given two linked lists head1 and head2, the task is to complete the function findIntersection(), 
which returns the intersection of two linked lists. Each of the two linked lists contains distinct node values.

Note: The order of nodes in this list should be the same as the order in which those particular nodes appear 
in input head1 and return null if no common element is present.*/

class Node{
    public:
    int data ;
    Node* next;
    Node(int value){
        this ->data=value;
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

Node* findIntersection(Node* head1, Node* head2){
   
    unordered_map<int,int>mp;
    Node* temp=head2;
    while(temp){
        mp[temp->data]++;
        temp=temp->next;
    }
    Node* dummy=new Node(0);
    Node* curr=dummy;
    temp=head1;
    while(temp){
        if(mp.find(temp->data)!=mp.end()){
            curr->next=new Node(temp->data);
            curr=curr->next;
        }
        temp=temp->next;
    }
    return dummy->next;
}
int main(){
    Node* head1=NULL;
    Node* head2=NULL;
    insert_end(9,head1);
    insert_end(6,head1);
    insert_end(4,head1);
    insert_end(2,head1);
    insert_end(3,head1);
    insert_end(8,head1);
    insert_end(1,head2);
    insert_end(2,head2);
    insert_end(8,head2);
    insert_end(6,head2);
    Node* newHead=findIntersection(head1,head2);
    printll(newHead);
}