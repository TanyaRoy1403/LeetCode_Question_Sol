#include<iostream>
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
Node* insert_end(int value,Node*& head1){
        Node* newNode=new Node(value);
        if(head1==NULL){
            head1=newNode;
        }else{
            Node* temp=head1;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newNode;
            newNode->next=NULL;
        }
    return head1;
}
Node* insert_end2(int value,Node*& head2){
        Node* newNode=new Node(value);
        if(head2==NULL){
            head2=newNode;
        }else{
            Node* temp=head2;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newNode;
            newNode->next=NULL;
        }
    return head2;
}
void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
Node* merge_ll(Node*& head1,Node*& head2){
      // Create a dummy node for the final linked list
    Node* dummy = new Node(0);
    // Pointer to track the merged linked list
    Node* k = dummy;

    Node* i = head1;
    Node* j = head2;

    while (i && j) {
        if (i->data <= j->data) {
            k->next = i;
            i = i->next;
        } else {
            k->next = j;
            j = j->next;
        }
        k = k->next;
    }

    // Append any remaining nodes from head1 or head2
    while (i) {
        k->next = i;
        k = k->next;
        i = i->next;
    }
    while (j) {
        k->next = j;
        k = k->next;
        j = j->next;
    }

    return dummy->next; // Return the merged list starting from the next of dummy

}
int main(){
    Node* head1=NULL;
    Node* head2=NULL;
    insert_end(5,head1);
    insert_end(10,head1);
    insert_end(15,head1);
    
    insert_end2(2,head2);
    insert_end2(3,head2);
    insert_end2(20,head2);
    Node* finalHead=merge_ll(head1,head2);
    printList(finalHead);


}