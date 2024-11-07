#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node*left;
    Node* right;
    Node(int value){
        this->data=value;
        left=NULL;
        right=NULL;
    }
};
Node* findMIn(Node* root){
    while(root->left!= NULL){
        root=root->left;
    }
    return root;
}
Node* deletionOfNode(Node* root,int target){
    if(root==NULL){
        return NULL;
    }
    //search the target
    if(target<root->data){
        root->left=deletionOfNode(root->left,target);
    }
    else if(target>root->data){
        root->right=deletionOfNode(root->right,target);
    }
    else{
        //target has no child 
        if(root->left==NULL&& root->right==NULL){
            delete root;
            return NULL;
        }
        //target has only one node(left)
        else if(root->left!=NULL&& root->right==NULL){
            //left ko store kr lo
            Node* storeleft=root->left;
            //ab delete kr do root ko
            delete root;
            //return the stored root
            return storeleft;
        }
        //target has only one node(right)
        else if(root->left==NULL&& root->right!=NULL){
            //right ko store kr lo
            Node* storeright=root->right;
            //ab delete kr do root ko
            delete root;
            //return the stored root
            return storeright;
        }
        //target has both child( left and right)
        //phele inorder succesor find kro(smallest node in the right subtree)
        Node* temp=findMIn(root->right);
        root->data=temp->data;
        //delete inorder successor 
        root->right = deletionOfNode(root->right, temp->data);
    }
    return root;
}
void printBST(Node* root) {
    if (root == NULL) {
        return;
    }
    printBST(root->left);
    cout << root->data << " ";
    printBST(root->right);
}
int main(){
    Node* root=new Node(5);
    root->left=new Node(3);
    root->right=new Node(6);
    root->left->left=new Node(2);
    root->left->right=new Node(4);
    root->right->right=new Node(7);
    root=deletionOfNode(root,3);
    printBST(root);
    return 0;
}