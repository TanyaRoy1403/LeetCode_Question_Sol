#include<iostream>
#include<unordered_set>
#include<unordered_map>
using namespace std;

/*Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. 
Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. 
Note that pos is not passed as a parameter.

Do not modify the linked list.*/

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

/*--------------------//^Brute force ,finding starting node  from where cycle is started----------------------------------*/
Node* cyclic_LL(Node* &head){
    unordered_set<Node*>visited;
  
    Node* temp=head;
    while(temp!=NULL){
        if(visited.find(temp)!=visited.end()){
            return temp;
        }
        visited.insert(temp);
        temp=temp->next;
    }
    return temp;
}

/*--------------------//^Brute force ,finding starting ka index  from where cycle is started----------------------------------*/

int cyclic_LL2(Node* &head){
    unordered_map<Node*,int>visited;  //map to keep track of index of visited node
  
    Node* temp=head;
    int index=0;
    while(temp!=NULL){
        if(visited.find(temp)!=visited.end()){
            return visited[temp];
        }
        visited[temp]=index;
        temp=temp->next;
        index++;
    }
    return -1;
}

int main(){
    Node* head=NULL;
    insert_end(3,head);
    insert_end(2,head);
    insert_end(0,head);
    insert_end(4,head);
    head->next->next->next->next = head->next;

    int cycleIndex = cyclic_LL2(head);
    cout<<cycleIndex;
}