#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};
void inorderStore(Node*root,vector<int>&ans){
    if(root==NULL){
        return;
    }
    inorderStore(root->left,ans);
    ans.push_back(root->data);
    inorderStore(root->right,ans);
}
Node* solve(int start,int end,vector<int>&ans){
    if(start>end){
        return NULL;
    }
    int mid=start+(end-start)/2;
    Node* root=new Node(ans[mid]);
    root->left=solve(start,mid-1,ans);
    root->right=solve(mid+1,end,ans);
return root;
}
Node* balancedBST(Node*root){
    vector<int>ans;
    inorderStore(root,ans);
    int start=0;
    int end=ans.size()-1;
    return solve(start,end,ans);
}
void printBST(Node* root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<" ";
    printBST(root->left);
    printBST(root->right);
}

int main(){
    Node* root=new Node(1);
    root->right=new Node(2);
    root->right->right=new Node(3);
    root->right->right->right=new Node(4);
    root=balancedBST(root);
    printBST(root);
    


}