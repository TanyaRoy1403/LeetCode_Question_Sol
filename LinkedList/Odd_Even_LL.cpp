#include<iostream>
#include<vector>
using namespace std;

/*Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes 
with even indices, and return the reordered list.

The first node is considered odd, and the second node is even, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

You must solve the problem in O(1) extra space complexity and O(n) time complexity.*/

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

Node* odd_even(Node* &head){
    //empty
    if(head==NULL){
        return head;
    }
    Node* odd=head;
    Node* even=head->next;
    Node* evenkaStart=head->next;  //last me jab odd ek side and even ek side ho jayega tb odd part ko even se connect krne ke liye
    while(even!=NULL&&even->next!=NULL){
        odd->next=even->next;
        even->next=even->next->next;
        odd=odd->next;  //aage bdho
        even=even->next;
    }
    //odd part ko even part se linking
    odd->next=evenkaStart;
    return head;
}

Node* odd_even_brute(Node* &head){
    if(head==NULL){
        return head;
    }
    Node* oddDummy=new Node(0); //dummy node to point odd wala ka head
    Node* evenDummy=new Node(0); //dummy node to pint even wala ka head;
    Node* oddpointer=oddDummy; //ek pointer jo odd wala part ko point krega or sath hi sath head ko v odd wala ka
    Node* evenpointer=evenDummy;
    Node* curr=head;  //current node
    int index=1;
    while(curr!=NULL){
        if(index%2!=0){
            oddpointer->next=curr;
            oddpointer=oddpointer->next;
        }else{
            evenpointer->next=curr;
            evenpointer=evenpointer->next;
        }
        curr=curr->next;
        index++;
    }
     // Combine the odd-indexed list with the even-indexed list
    oddpointer->next = evenDummy->next;
    evenpointer->next = NULL;
    Node* newHead=oddDummy->next;
    delete oddDummy;
    delete evenDummy;
    return newHead;
}
int main(){
    Node* head=NULL;
    insert_end(1,head);
    insert_end(2,head);
    insert_end(3,head);
    insert_end(4,head);
    insert_end(5,head);
    printll(head);
    cout<<endl;
    head=odd_even_brute(head);
    printll(head);
}