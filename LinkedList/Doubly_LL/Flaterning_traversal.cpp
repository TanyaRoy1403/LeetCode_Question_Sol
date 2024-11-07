#include<iostream>
#include<vector>
using namespace std;

/*You are given a doubly linked list, which contains nodes that have a next pointer, a previous pointer,
 and an additional bottom pointer. This bottom pointer may or may not point to a separate doubly linked list, 
 also containing these special nodes. These bottom lists may have one or more children of their own, and so on, 
 to produce a multilevel data structure as shown in the example below.

Given the head of the first level of the list, flatten the list so that all the nodes appear in a single-level, doubly linked list. 
Let curr be a node with a bottom list. The nodes in the bottom list should appear after curr and before curr.next in the flattened list.

Return the head of the flattened list. The nodes in the list must have all of their bottom pointers set to null.*/

class Node {
public:
    int data;
    Node* next;
    Node* bottom;
    Node* prev;
    Node(int value) {
        this->data = value;
        this->next = NULL;
        this->bottom = NULL;
        this->prev=NULL;
    }
};

// Function to print the flattened linked list
void printll(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Function to insert a node at the end of the bottom linked list
Node* insert_bottom(Node* head, int value) {
    Node* newNode = new Node(value);
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->bottom != NULL) {
            temp = temp->bottom;
        }
        temp->bottom = newNode;
    }
    return head;
}

Node *flattenEnd(Node *head){
    
   if (!head) return head;
   Node *fp = head, *next;
   while (fp)
   {
       next = fp->next;
       if (fp->bottom)
       {
           Node *end = flattenEnd(fp->bottom);
           fp->next = fp->bottom;
           fp->next->prev = fp;
           fp->bottom = NULL;
           fp = end;
           fp->next = next;
           if(next)
               next->prev = end;
       }
       if (!next)
           break;
       fp = next;
   }
   return fp;
}
Node* flatten(Node* head) {
        flattenEnd(head);
        return head;
}
int main(){
     Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;

    head->next->next = new Node(3);
    head->next->next->prev = head->next;

    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;

    head->next->next->next->next = new Node(5);
    head->next->next->next->next->prev = head->next->next->next;

    head->next->next->next->next->next = new Node(6);
    head->next->next->next->next->next->prev = head->next->next->next->next;

    // Creating bottom nodes
    Node* node2 = head->next;
    node2->bottom = new Node(7);
    node2->bottom->next = new Node(8);
    node2->bottom->next->prev = node2->bottom;

    node2->bottom->next->next = new Node(9);
    node2->bottom->next->next->prev = node2->bottom->next;

    node2->bottom->next->next->next = new Node(10);
    node2->bottom->next->next->next->prev = node2->bottom->next->next;

    Node* node8 = node2->bottom->next;
    node8->bottom = new Node(11);
    node8->bottom->next = new Node(12);
    node8->bottom->next->prev = node8->bottom;

    Node* newHead = flatten(head);
    printll(newHead);
}