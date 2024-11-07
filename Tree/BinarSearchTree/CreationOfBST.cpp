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

Node* insertNode(Node* root,int val){
    Node* newNode=new Node(val);
    if(root==NULL){
        return newNode;
    }
    if(val<root->data){
        root->left=insertNode(root->left,val);
    }
    else if(val>root->data){
        root->right=insertNode(root->right,val);
    }
    return root;
}

Node* creationBST(Node*root,vector<int>&input){
    if(root==NULL){
        return NULL;
    }
    for(int i=0;i<input.size();i++){
        root=insertNode(root,input[i]);
    }
    return root;
    
}

void printBST(Node*root){
    if(root==NULL){
        return;
    }
    printBST(root->left);
    cout<<root->data<<" ";
    printBST(root->right);
}
int main(){
    Node* root=NULL;
    vector<int>input={10, 5, 15, 3, 7, 13, 17};
    root=creationBST(root,input);
    printBST(root);
}