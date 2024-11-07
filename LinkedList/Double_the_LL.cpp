#include<iostream>
#include<vector>
using namespace std;

//! 3 approach
//~1-->reverse and then multipcarry
//~2-->stack
//~ recursion

//^ aaproach 1(reverse)

class Node{
    public:
    int data;
    Node* next;
    Node(int value){
        this->data=value;
        this->next=NULL;
    }
};
void printll(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
}
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
Node* reverse_list(Node*& head){
    Node* pre= NULL;
    Node* curr=head;
    if(head==NULL||head->next==NULL){
        return head;
    }
    while(curr!=NULL){
        Node* forward=curr->next;
        curr->next=pre;
        pre=curr;
        curr=forward;
    }
    return pre;
}
/*--------------------------------------------------------------------------------------------------------------------------------------------------*/
Node* Double_LL(Node*& head){
    //reverse the given list
    Node* newHead=reverse_list(head);
    //multipcarry bcarry 2
    Node* prev=NULL;  //jb carrcarry >0 hoga tb iss carrcarry ko ek aage wale node me fill krne ke licarrye
    Node* curr=newHead;
    int carry=0;
    int value=0;
    while(curr){
        value=(curr->data)*2+carry;
        curr->data=value%10;
        carry=value/10;
        prev=curr;
        curr=curr->next;
    }
        if(carry>0){
            Node* newNode=new Node(carry);
            prev->next=newNode;

        }
    newHead=reverse_list(newHead);
    return newHead;
/*Time complexity:O(n)----
---Space complexity:O(n)----------------------------------------------------------------------------------------------------------------------------*/
}

/*------------------------------------//&Using two pointer---------------------------------------------------------------------------------------*/
Node* Double_LL_2(Node*& head){
    Node* prev=NULL;
    Node* curr=head;
    while(curr){
        int value =curr->data*2;
        if(value<10){
            curr->data=value;
        }else{  //case  value>=10
            curr->data=value%10;
            if(prev==NULL){
                Node* newNode=new Node(1);
                head=newNode;
                head->next=curr;
            }
            else{
                //prev ==NULL or hm head pe khre h or head ka value double digit me h mtlb carry ek nye node jayega just like carry>0 wala case
                prev->data=prev->data+1;
            }
        }
        prev=curr;
        curr=curr->next;
    }
    return head;
    
}
int main(){
    Node* head=NULL;
    insert_end(9,head);
    insert_end(9,head);
    insert_end(9,head);
    // Node* newHead=Double_LL(head);
    // printll(newHead);
    // cout<<endl;
    Node* new_head=Double_LL_2(head);
    printll(new_head);
}