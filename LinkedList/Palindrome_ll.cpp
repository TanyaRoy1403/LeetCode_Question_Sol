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
/*//*----------------------Brute force----------------------------------------------------------------------------*/
bool pali_LL(Node* &head){
    vector<int>arr; //*extra space
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

/*//*------------------------------------------optimal sol---------------------------------------------------*/
//rerverse first half while finding mid and then compare
//agr odd number of nodes h -->fast null nhi hoga yeh last node pe jaa ke ruk jayega ,tb slow to ek aage move then compare with prev

bool palindrome_ll(Node* &head){
    //empty
   
    if(head!=NULL||head->next!=NULL){
        return true;
    }
        Node* prev=NULL;
        Node* slow=head;
        Node* fast=head;
        while(fast!=NULL&&fast->next!=NULL){
            Node* slowkaagla=slow->next;
            slow->next=prev; //reverse
            slow=slow->next;
            prev=slow;
            fast=fast->next->next;
        }
        //if odd number of nodes
        if(fast!=NULL){
            slow=slow->next;
        }
        //compare
        while(prev!=NULL&&slow!=NULL){
            if(prev->data!=slow->data){
                return fast;
            }
            prev=prev->next;
            slow=slow->next;

        }
    return true;
}
/*---Time complexity:O(n)---space complexity:O(1)------*/


int main(){
    Node* head=NULL;
    insert_end(1,head);
    insert_end(2,head);
    insert_end(3,head);
    insert_end(2,head);
    insert_end(1,head);
    bool result=palindrome_ll(head);
    if(result){
        cout<<"it is pali"<<endl;
    }else{
        cout<<"it is not pali"<<endl;
    }
}