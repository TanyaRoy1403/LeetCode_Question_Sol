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
void del_n_node(Node*& head,int n,int m){
        Node* pre = head;
        Node* cur = head;
        if(n>m || head->next==NULL){
            return ;
        }

        while (pre != nullptr) {
            // Move `pre` m-1 steps ahead
            for (int i = 1; i < m && pre != nullptr; i++) {
                pre = pre->next;
            }

            // If `pre` is null, then we are done
            if (pre == nullptr) {
                break;
            }

            // Set `cur` to the next node after `pre`
            cur = pre->next;

            // Move `cur` n steps ahead
            for (int i = 0; i < n && cur != nullptr; i++) {
                cur = cur->next;
            }

            // Link `pre` to `cur` (skip `n` nodes)
            pre->next = cur;

            // Move `pre` to `cur`
            pre = cur;
    }
}
int main(){
    Node* head=NULL;
    insert_end(9,head);
    insert_end(1,head);
    insert_end(3,head);
    insert_end(5,head);
    insert_end(9,head);
    insert_end(4,head);
    insert_end(10,head);
    insert_end(1,head);
    int n=1;
    int m=2;
    del_n_node(head,n,m);
    printll(head);

}

