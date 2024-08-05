#include<iostream>
#include<vector>
using namespace std;

//^creation of node class

class Node{
public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        next=NULL;
    }
};

class LinkedList{
public:
   //*attribute define
    Node* head;
    Node* tail;

    //*constructor define jo modifiable bnayega
    LinkedList(){
        head=NULL;
        tail=NULL;
    }
      
    void insertAtTail(int value) {
        Node* newNode = new Node(value);
        if (head == NULL && tail == NULL) {
            // LL is empty
            head = newNode;
            tail = newNode;
        } else {
            // LL is not empty
            tail->next = newNode;
            tail = newNode;
        }
    }
    void insertAtbe(int value){
        //^empty
        Node* newNode=new Node(value);
        if(head==NULL&&tail==NULL){
            head=newNode;
            tail=newNode;
        }else{
            newNode->next=head;
            head=newNode;
        }
    }

    void print(){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
        cout<<"NULL";
}
void printtail(){
    if(tail!=NULL){
        cout<<"tail"<<tail->data<<endl;
    }else{
        cout<<"not tail";
    }
}

 

};


int main(){

        //^creating nodes statically
        LinkedList* obj=new LinkedList();

        //^phele se agr node present ho

        Node* pre=new Node(45);
        obj->head=pre;
        Node* n2=new Node(60);
        pre->next=n2;
        Node* n3=new Node(70);
        n2->next=n3;
        Node* n4=new Node(80);
        n3->next=n4;
        obj->tail=n4;
        n4->next=NULL;
        // obj->insertAtbe(50);
        obj->print();
        cout<<endl;
        obj->printtail();


       
        
        
        

}