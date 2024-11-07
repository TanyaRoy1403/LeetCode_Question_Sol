#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* bottom;
    Node(int value) {
        this->data = value;
        this->next = NULL;
        this->bottom = NULL;
    }
};

// Function to print the flattened linked list
void printll(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->bottom;
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

// Function to merge two sorted linked lists
Node* merge_ll(Node*& head1, Node*& head2) {
    Node* dummy = new Node(0);
    Node* k = dummy;

    Node* i = head1;
    Node* j = head2;

    while (i && j) {
        if (i->data <= j->data) {
            k->bottom = i;
            i = i->bottom;
        } else {
            k->bottom = j;
            j = j->bottom;
        }
        k = k->bottom;
    }

    while (i) {
        k->bottom = i;
        k = k->bottom;
        i = i->bottom;
    }

    while (j) {
        k->bottom = j;
        k = k->bottom;
        j = j->bottom;
    }

    return dummy->bottom; // Return the merged list starting from the bottom of dummy
}

// Function to flatten the linked list
Node* flat_ll(Node*& head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
   Node* head1 = flat_ll(head->next);
    return merge_ll(head, head1);
}

int main() {
    Node* head = new Node(5);
    head->bottom = insert_bottom(head->bottom, 7);
    head->bottom = insert_bottom(head->bottom, 8);
    head->bottom = insert_bottom(head->bottom, 30);

    head->next = new Node(10);
    head->next->bottom = insert_bottom(head->next->bottom, 20);

    head->next->next = new Node(19);
    head->next->next->bottom = insert_bottom(head->next->next->bottom, 22);
    head->next->next->bottom = insert_bottom(head->next->next->bottom, 50);

    head->next->next->next = new Node(28);
    head->next->next->next->bottom = insert_bottom(head->next->next->next->bottom, 35);
    head->next->next->next->bottom = insert_bottom(head->next->next->next->bottom, 40);
    head->next->next->next->bottom = insert_bottom(head->next->next->next->bottom, 45);

    // Flatten the linked list
    Node* flattenedList = flat_ll(head);

    // Print the flattened linked list
    printll(flattenedList);

    return 0;
}
