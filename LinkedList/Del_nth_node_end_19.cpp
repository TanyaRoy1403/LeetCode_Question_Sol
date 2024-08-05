#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        this->data = value;
        this->next = NULL;
    }
};

int getLength(Node*& head) {
    int length = 0;
    Node* temp = head;
    while (temp != NULL) {
        temp = temp->next;
        length++;
    }
    return length;
}

Node* insert_end(int value, Node*& head) {
    Node* newNode = new Node(value);
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return head;
}

void printll(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
/*//^----------------------------------------------brute force-------------------------------------------------------------*/
Node* remove_nth(Node*& head, int n) {
    int len = getLength(head);
    if (head == NULL || n > len) {
        return head;
    }
    if (head->next == NULL && n == 1) {
        delete head;
        head = NULL;
        return head;
    }
    //^last wala delete krna ho yeh len-n+1 wala case se fail ho ja rha h isliyye special handle
    if (n == 1) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node* temp = head;
    for (int i = 1; i < len - n; i++) {
        temp = temp->next;
    }
    Node* nodetobedel = temp->next;
    temp->next = nodetobedel->next;
    delete nodetobedel;
    return head;
}
/*//*--------------------------------------------------------------optimal(two pointers)-------------------------------------------------------- */
Node* del_nth( Node*&head,int n){
    //!dummy node
    Node* dummy=new Node(0);  //*0->1->2->3->4->5 ,n=2
    dummy->next=head;
    Node* pre=dummy;
    Node* curr=dummy;
    //^move curr to n+1 node;
    for(int i=0;i<=n;i++){  //*curr->3 pre->0   agr aisa nhi kiye to agr target node head nikla fir isko alg se handle krna prega
        curr=curr->next;
    }
    //^move curr and pre till curr reach last;
    while(curr!=NULL){
        pre=pre->next;   //*pre->2  target(pre)= pre->next
        curr=curr->next;  //*curr->null
                         //*pre->next=pre->next->next
    }
    Node* nodetobedel=pre->next;
    pre->next=nodetobedel->next;
    delete nodetobedel;
    Node* newhead =dummy->next;  //* i.e 1
    delete dummy;
    return newhead;
}
/*//*------------------------------------------------my intuition---------------------------------------------------------*/
Node* remove_nth_end(Node* &head,int n){
    int lenght=getLength(head);
    if(n>lenght){
        return head;
    }
    if(n==lenght){  //!deletion krna h head ko hi (len-n+1) 1->2->3->4->5
        Node* newHead=head->next;      //^delete krne se phele 2 ko as a nya head bnana hoga
        delete head;
        return newHead;
    }
    //pointers
    Node* pre=NULL;
    Node* curr=head;
    for(int i=0;i<lenght-n;i++){
        pre=curr;
        curr=curr->next;
    }
    pre->next=curr->next;
    delete curr;
    return head;
}
int main() {
    Node* head = NULL;
    insert_end(1, head);
    insert_end(2, head);
    insert_end(3, head);
    insert_end(4, head);
    insert_end(5, head);

    cout << "Original Linked List: ";
    printll(head);

    int n = 2;
    // head = del_nth(head, n);
    // cout<<endl;
    head=remove_nth_end(head,n);

    cout << "Linked List after removing " << n << "th node from end: ";
    printll(head);

    return 0;
}
