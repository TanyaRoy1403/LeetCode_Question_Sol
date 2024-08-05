#include<iostream>
using namespace std;

class Node{
    public:
    //^attributes
    int data;
    Node* next;

    //^constructor
    Node(int value){
        this->data=value;
        this ->next=NULL;
    }
};

//^operation on ll

//*insertion at beg
Node* insert_beg(int value ,Node*& head){  //!return type node*--> we have to send head with ref so that if change head it reflect ot original head
    // new node                           //! return type void--> simply send head as -->Node* head
    Node* newNode=new Node(value);
    //ll empty
    if(head==NULL){
        head=newNode;
    }else{
        newNode->next=head;
        head=newNode;
    }
    return head;
}
//* insertion at end
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
//* insertion after the specific node(value)-->kisi v given node ke value ke badd insert
Node* insert_after_value(int value,int data,Node*& head){
    Node* newNode=new Node(data);
    if(head==NULL){
        head=newNode;
    }else{
        Node* temp=head;
        while(temp!=NULL&&temp->data!=value){
            temp=temp->next;
        }
        if (temp != NULL) {
            newNode->next = temp->next;
            temp->next = newNode;
        } else {
            cout << "Value " << value << " not found in the list." << endl;
        }

    }
return head;
}
//&length function
int getLength(Node* head) {
  int len = 0;
  Node* temp = head;

  while(temp != NULL) {
    temp = temp->next;
    len++;
  }
  return len;
}

//*INsertion at given index
Node* insertion_idx(int value,int pos,Node*& head){  //*one based indexing
    Node* newNode=new Node(value);
    int length = getLength(head);
    if(pos== 1) {
        //insert at ahead krna chahta hu 
        return insert_beg(value, head);
    }
    else if(pos == length + 1) {
        //insert at tail krna chahta hu 
        return insert_end(value, head);
    }
    else {
        //insert in between kahin krna chahta hu 
        Node* temp = head;
        for(int i=0; i<pos-2; i++) {  //*do case to dekh chuke beg and end
        temp = temp -> next;
        }
        Node* newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;
    }
return head;
}
//*deletion at beginnig
Node* delete_beg(Node*& head){
    if(head==NULL){
        return head;
    }
    if(head->next==NULL){
        delete head;
        head=NULL;
    }
    else{
        Node* temp=head;
        head=head->next;
        delete temp;
    }
    return head;
}

//* DELETION after the specific node(value)-->kisi v given node ke value ke badd delete
Node* deletion_after_value(int value,Node*& head){
    if(head==NULL){
        cout<<"deletion not possible"<<endl;
    }else{
        Node* temp=head;
        while(temp!=NULL&& temp->data!=value){

            temp=temp->next;
        }
        if(temp!=NULL&&temp->next!=NULL){
            Node* nodetodelete=temp->next;
            temp->next=nodetodelete->next;
            delete nodetodelete;
        }
    }
    return head;
}

//^deletion by value
Node* delete_by_val(int value,Node*& head){
    Node* temp=head;
    if(head==NULL){
        return head;
    }
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    if (temp->next == nullptr) {
        cout << "Value not found in the list" << endl;
        return head;
    }
    else{
        Node* temp=head;
        while(temp->next!=NULL&&temp->next->data!=value){
            temp=temp->next;
        }
        Node* tobeDelet=temp->next;
        temp->next=tobeDelet->next;
        delete tobeDelet;
    }
    return head;
}
//*deletion at end
Node* delete_end(Node*& head){
    //^ll empty
    if(head==NULL){
        cout<<"deletion not possible"<<endl;
    }
    //^only one node present
    if(head->next==NULL){
        delete head;
        head=NULL;
    }else{
        //^more than one node
        Node* temp=head;
        //traves to the secode last node --(delte hone wale node se ek phele wale node tk)
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        delete temp->next; //^delete last node
        temp->next=NULL; //^second last walo null set kr deyge

    }
    return head;

}

bool search(int target,Node*& head){
    Node* temp=head;
    while(temp!=NULL){
        if(temp->data=target){
            return true;
        }
        temp=temp->next;
    }
    return false;
}
//^reversing ll using iteration
Node* reverseList(Node*& head){
    //creating pointers
    Node* first=NULL;
    Node* curr=head;
    Node* forward_pointer=NULL;
    while(curr!=NULL){
        forward_pointer=curr->next;
        curr->next=first;
        first=curr;
        curr=forward_pointer;
    }
    return first;
}
//^reversing ll using recursion 
Node* reverse_ll(Node*& pre,Node*& curr){
    //base case
    if(curr==NULL){
        return pre;
    }
    Node* forward=curr->next;
    //reverse
    curr->next=pre;
    pre=curr;
    curr=forward;
    return pre;
}


//^print function

void printll(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
}

//main fnction
int main(){
    Node* head=NULL;    
    insert_beg(10,head);
    insert_beg(20,head);
    insert_end(30,head);
    insert_beg(40,head);
    // insertion_idx(56,2,head);
    head=reverseList(head);
    delete_beg(head);
    
    printll(head);
}