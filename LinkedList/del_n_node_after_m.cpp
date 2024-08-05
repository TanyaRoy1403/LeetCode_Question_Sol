#include<iostream>
using namespace std;
/*Given a linked list and two integers M and N. Traverse the linked list such that you retain M nodes then 
delete next N nodes, continue the same till end of the linked list.*/
class Node{
    public:
    int data;
    Node* next;
    Node(int value){
        this->data=value;
        this->next=NULL;
    }

};
Node* del_n_node(Node*head){
    
}

