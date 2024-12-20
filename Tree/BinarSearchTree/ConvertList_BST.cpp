#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int value){
        this->data=value;
        left=NULL;
        right=NULL;
    }
};
class ListNode{
    public:
    int val;
    ListNode* next;
    ListNode(int x){
        this->val=x;
        next=NULL;
    }
};
ListNode* insert_end(int value,ListNode*& head){
        ListNode* newNode=new ListNode(value);
        if(head==NULL){
            head=newNode;
        }else{
            ListNode* temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newNode;
            newNode->next=NULL;
        }
    return head;
}
Node* solve(vector<int>&arr,int  s,int e){
    //base case
    if(s>e){
        return NULL;
    }
    int mid=s+(e-s)/2;
    Node* root=new Node(arr[mid]);
    root->left=solve(arr,s,mid-1);
    root->right=solve(arr,mid+1,e);
    return root;

}
Node* listbstMain(ListNode* head){
    vector<int>arr;
    while(head){
        arr.push_back(head->val);
        head=head->next;
    }
    int n=arr.size();
    int s=0;
    int e=n-1;
    Node* root=solve(arr,s,e);
    return root;
}
void printBst(Node* root){
    if(root==NULL){
        return ;
    }
    printBst(root->left);
    cout<<root->data<<" ";
    printBst(root->right);
}
int main(){
    ListNode* head=NULL;
    insert_end(-10,head);
    insert_end(-3,head);
    insert_end(0,head);
    insert_end(5,head);
    insert_end(9,head);
    Node* root=listbstMain(head);
    printBst(root);

}