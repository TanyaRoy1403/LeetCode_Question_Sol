#include<iostream>
#include<vector>
using namespace std;

/*Given the head of a singly linked list and an integer k, split the linked list into k consecutive linked list parts.

The length of each part should be as equal as possible: no two parts should have a size differing by more than one. 
This may lead to some parts being null.

The parts should be in the order of occurrence in the input list, and parts occurring earlier should always have a size greater 
than or equal to parts occurring later.

Return an array of the k parts.*/


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
int getLength(Node* head) {
  int len = 0;
  Node* temp = head;

  while(temp != NULL) {
    temp = temp->next;
    len++;
  }
  return len;
}
vector<Node*> split_k(Node*& head,int k){
    int len=getLength(head);
    vector<Node*>ans(k,NULL);
    if(head==NULL){
        return ans;
    }
    Node* prev=NULL; //link thorne ke liye
    Node* curr=head;
    int requireNode= len/k;
    int extraNode=len%k;
    for(int i=0;i<k&&curr!=NULL;i++){
        ans[i]=curr;
        //extra wale ko insert krenge splitted part me
        for(int j=0;j<requireNode+(extraNode>0?1:0);j++){
            //pointer move
            prev=curr;
            curr=curr->next;
        }
        prev->next=NULL;
        extraNode--;
    }
    return ans;
}
/*//^---------------------------------------Brute force-------------------------------------------------------*/
vector<Node*> split_into_k(Node*& head,int k){
    vector<Node*>ans(k,NULL);
    //pointer define
    Node* pre=NULL;
    Node* curr=head;
    int len=getLength(head);
    int base_size=len/k; // actual me part me kitna element hoga without considering bcaha hua nodes
    int extra_node=len%k;
    for(int i=0;i<k&& curr!=NULL;i++){
        ans[i]=curr;
        int part_size=base_size+(extra_node>0?1:0); //splitd part me kitna ele hoga after considering extra noode
        extra_node--;
        for(int j=0;j<part_size;j++){
            pre=curr;
            curr=curr->next;
        }
        pre->next=NULL;
    }
    return ans;
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
    insert_end(4,head);
    insert_end(5,head);
    insert_end(6,head);
    insert_end(7,head);
    insert_end(8,head);
    insert_end(9,head);
    insert_end(10,head);
    int k=4;
    vector<Node*>ans=split_into_k(head,k);
    for(auto &it:ans){
        printll(it);
    cout<<endl;
    }

}