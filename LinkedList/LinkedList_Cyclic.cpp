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
    unordered_set<Node*>visited;  //set to keep track of node only
  
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

/*//^--------------------optimal solution (slow and fast pointer)------------------------------------------*/
//node return krna h

Node* detect_cycle(Node* &head){
    //empty  ya one node
    if(head==NULL ||head->next==NULL){
        return head;
    }
    Node* startingNodeCycle=head;
    Node* slow=head;
    Node* fast=head;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        //agr cycle mil gya 
        if(slow==fast){
            while(startingNodeCycle!=slow){
                startingNodeCycle=startingNodeCycle->next;
                slow=slow->next;
            }
            return startingNodeCycle;
        }
    }
    return NULL;
}

//~Remove cycle
void remove_cycle(Node*& head){
         Node* cycle_start = detect_cycle(head);
    
    if (cycle_start == NULL) {
        return;  // No cycle detected
    }
    
    Node* temp = cycle_start;
    
    // Find the node just before the start of the cycle
    while (temp->next != cycle_start) {
        temp = temp->next;
    }
    
    // Break the cycle
    temp->next = NULL;
}


/*//^--------------------optimal solution (slow and fast pointer)------------------------------------------*/
//node ka index return krna h

int detect_cycle2(Node* &head){
    //empty  ya one node
    if(head==NULL ||head->next==NULL){
        return -1;
    }
    Node* startingNodeCycle=head;
    Node* slow=head;
    Node* fast=head;
    int indx=0;
    int startingindex=0;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        indx++;
        //agr cycle mil gya 
        if(slow==fast){
            while(startingNodeCycle!=slow){
                startingNodeCycle=startingNodeCycle->next;
                slow=slow->next;
                startingindex++;
            }
            return startingindex;
        }
    }
    return -1;
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
    insert_end(3,head);
    insert_end(2,head);
    insert_end(0,head);
    insert_end(4,head);
    head->next->next->next->next = head->next;
    Node* newHead=detect_cycle(head);
    if(newHead!=NULL){
        cout<<"cycle detected at node:"<<newHead->data<<endl;
    }else{
        cout<<"Cycle not detected"<<endl;
    }
    // int ans=detect_cycle2(head);
    // cout<<ans;
    remove_cycle(head);
    printll(head);


 
}