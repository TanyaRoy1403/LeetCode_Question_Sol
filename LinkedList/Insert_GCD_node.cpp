#include<iostream>
#include<numeric>   // For gcd
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int value){
        this->data = value;
        this->next = NULL;
    }
};

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

int find_gcd(int a,int b){
    while(b!=0){
            int temp = b;
            b = a % b;
            a = temp;
    }
    return a;
}
Node* insert_gcd_value(Node*& head) {
    if (head == NULL) {
        return head;
    }
    Node* curr = head;
    Node* forward = head->next;
    while (forward) {
        int gcd_value =find_gcd(curr->data, forward->data); //u can use gcd predefine func
        Node* newNode = new Node(gcd_value);
        curr->next = newNode;
        newNode->next = forward;
        curr = forward;
        forward = forward->next;
    }
    return head;
}

int main() {
    Node* head = NULL;
    insert_end(18, head);
    insert_end(6, head);
    insert_end(10, head);
    insert_end(3, head);

    head = insert_gcd_value(head);
    printll(head);
}
int main(){
    Node* head=NULL;
    insert_end(6,head);
}