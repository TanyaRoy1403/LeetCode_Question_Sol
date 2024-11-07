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
bool isPathsum(Node* root,int target){
    int sum=0;
    if(root==NULL){
        return false;
    }
    target-=root->data;
    //ek node ho bss
     if (root->left == NULL && root->right == NULL) {
        return (target == 0);
    }
 
    bool leftans=isPathsum(root->left,target);
    bool rightans=isPathsum(root->right,target);
    return leftans||rightans;
}
int main(){
    Node* root = new Node(5);
    root->left = new Node(4);
    root->right = new Node(8);
    root->left->left = new Node(11);
    root->left->left->left = new Node(7);
    root->left->left->right = new Node(2);
    root->right->left = new Node(13);
    root->right->right = new Node(4);
    root->right->right->right = new Node(1);


    bool result=isPathsum(root,22);
    if(result){
        cout<<"Target found:"<<endl;
    }else{
        cout<<"Target not found:"<<endl;
    }
    return 0;
}