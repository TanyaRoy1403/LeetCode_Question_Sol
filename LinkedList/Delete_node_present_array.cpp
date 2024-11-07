#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class Node{
     public:
     int data;
     Node*next;
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
Node* delete_node_present_arr(Node*& head,vector<int>&arr){
    unordered_set<int>st(arr.begin(),arr.end());
    //empty
    if(head==NULL){
        return head;
    }
    Node* dummy=new Node(0);
    dummy->next=head;
    Node* prev=dummy;
    Node* curr=head;
    while(curr){
        //agr arr me present ele node ka se mil gya
        if(st.find(curr->data)!=st.end()){
            //to delete kr deyege
            Node* temp = curr->next;  // Store the next node
            prev->next = curr->next;  // Adjust the link
            delete curr;              // Safely delete curr
            curr = temp;              // Move to the next node using temp

        }else{
            prev=curr;
            curr=curr->next;
        }
    }
    //deletion of dummy
    Node* newHead=dummy->next;
    delete dummy;
    return newHead;
}
int main(){
    Node* head=NULL;
    insert_end(1,head);
    insert_end(2,head);
    insert_end(1,head);
    insert_end(2,head);
    insert_end(1,head);
    insert_end(2,head);
    vector<int>arr={1};
    head=delete_node_present_arr(head,arr);
    printll(head);
}