#include<iostream>
#include<vector>
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
bool pali_LL(Node* &head){
    vector<int>arr;
    Node* temp=head;
    while(temp!=NULL){
    arr.push_back(temp->data);
        temp=temp->next;
    }
    int s=0;
    int e=arr.size()-1;
    while(s<e){
        if(arr[s]!=arr[e]){
            return false;
        }
        s++;
        e--;
    }
    return true;
}
int main(){
    Node* head=NULL;
    insert_end(1,head);
    insert_end(2,head);
    insert_end(3,head);
    insert_end(2,head);
    insert_end(1,head);
    bool result=pali_LL(head);
    if(result){
        cout<<"it is pali"<<endl;
    }else{
        cout<<"it is not pali"<<endl;
    }
}