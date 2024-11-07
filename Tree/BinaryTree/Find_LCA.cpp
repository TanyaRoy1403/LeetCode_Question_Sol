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
Node* LowestCommonAc(Node* root,Node* p,Node* q){
    if(root==NULL){
        return NULL;
    }
    if(root->data==p->data){
        return p;
    }
    if(root->data==q->data){
        return q;
    }
    Node* leftans=LowestCommonAc(root->left,p,q);
    Node* rightans=LowestCommonAc(root->right,p,q);
    if(leftans==NULL && rightans==NULL){
        return NULL;
    }else if(leftans!=NULL && rightans==NULL){
        return leftans;
    }
    else if(leftans==NULL&& rightans!=NULL){
        return rightans;
    }else{
        // dono hi null h mtlb main root hi LCA h
        return root;
    }

}
int  main(){
    Node* root=new Node(3);
    root->left=new Node(5);
    root->right=new Node(1);
    root->left->left=new Node(6);
    root->left->right=new Node(2);
    root->left->right->left=new Node(7);
    root->left->right->right=new Node(4);
    root->right->left=new Node(0);
    root->right->right=new Node(8);
    Node* p=root->left->right->left;
    Node* q=root->right->left;
     Node* lca = LowestCommonAc(root, p, q);
    
    if (lca != NULL) {
        cout << "LCA of tree with respect to p and q is: " << lca->data << endl;
    } else {
        cout << "No LCA found" << endl;
    }
}