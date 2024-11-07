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
//less optimal h time complexity-->o(n)
Node* LCAbst(Node* root,Node* p,Node* q){
    if(root==NULL){
        return NULL ;
    }
    if(root->data==p->data){
        return p;
    }
    if(root->data==q->data){
        return  q;
    }
    //agr left child null h or right nhi h tb
    Node* leftchild=LCAbst(root->left,p,q);
    Node* rightchild=LCAbst(root->right,p,q);
    if(leftchild==NULL&& rightchild!=NULL){
        return rightchild;
    }
    else if(leftchild!=NULL&& rightchild==NULL){
        return leftchild;
    }else if(leftchild==NULL&& rightchild==NULL){
        return NULL;
    }
    else{
        return root;
    }
}
//binary search ka property lgao or kisi ek side jao sirf
Node* lca_bst(Node* root,Node*  p,Node* q){
    if(root==NULL){
        return NULL;
    }
    //agr p and q dono leftsubtree me present ho to sirf left jao
    if(p->data<root->data&& q->data<root->data){
        return lca_bst(root->left,p,q);
    }
    //agr dono rightsubtree me present ho tb sirf right jao
    if(p->data>root->data&& q->data >root->data){
        return lca_bst(root->right,p,q);
    }
    //agr dono alg alg subtree me present ho 
    //tb to root hi uska LCA hoga n
    return root;
}

int main(){
    Node*root =new Node(6);
    root->left=new Node(2);
    root->right=new Node(8);
    root->left->left=new Node(0);
    root->left->right=new Node(4);
    root->left->right->left=new Node(3);
    root->left->right->right=new Node(5);
    root->right->left=new Node(7);
    root->right->right=new Node(9);
    Node*p=root->left=new Node(2);
    Node* q=root->right->right=new Node(9);

    Node* lca = LCAbst(root, p, q);
    
    if (lca != NULL) {
        cout << "LCA of tree with respect to p and q is: " << lca->data << endl;
    } else {
        cout << "No LCA found" << endl;
    }
    cout<<endl;
    cout<<endl;
    
    Node* lca2 = lca_bst(root, p, q);
    
    if (lca != NULL) {
        cout << "LCA of tree with respect to p and q is: " << lca2->data << endl;
    } else {
        cout << "No LCA found" << endl;
    }

    return 0;
}