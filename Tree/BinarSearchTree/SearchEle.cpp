#include<iostream>
#include<vector>
using namespace std;

struct Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int value): data(value),left(NULL),right(NULL){};
};

bool search(Node* root,int target){
    if(root==NULL){
        return false;
    }
    if(root->data==target){
        return true;
    }
    //agr nhi mila or left ya right jana pra
    else if(root->data>target){
        return search(root->left,target);
    }else{
        return search(root->right,target);
    }
}
int main(){
     Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(3);
    root->left->right = new Node(7);
    root->right->left = new Node(13);
    root->right->right = new Node(17);

    bool result=search(root,20);
    if(result){
        cout<<"Found"<<endl;
    }else{
        cout<<"Not found"<<" ";
    }
    return 0;
}