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

void inorder(Node* root,int& k,int &res){
    if(root==NULL||k<0){
        return;
    }
    //left jao
    inorder(root->left,k,res);
    k--;
    if(k==0){
        res=root->data;
        return;
    }
    //right chlo
    inorder(root->right,k,res);

}
int kthsmallest(Node* root,int k){
    int res=-1;
    inorder(root,k,res);
    return res;
}
int main(){
    Node* root=new Node(3);
    root->left=new Node(1);
    root->right=new Node(4);
    root->left->right=new Node(2);
    int result=kthsmallest(root,4);
    cout<<result;
    return 0;
}