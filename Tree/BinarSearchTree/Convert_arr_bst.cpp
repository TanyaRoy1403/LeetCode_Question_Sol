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
Node* solve(vector<int>&arr,int start,int end){
    //base case
    if(start>end){
        return NULL;
    }
    int mid=start+(end-start)/2;
    Node* root=new Node(arr[mid]);
    root->left=solve(arr,start,mid-1);
    root->right=solve(arr,mid+1,end);
    return root;
}
Node* sortedToBST(vector<int>&arr){
    int n=arr.size();
    int start=0;
    int end=n-1;
    return solve(arr,start,end);
}
void preorder(Node*root){
    if(root==NULL){
        return ;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main(){
    vector<int>arr={-10,-3,0,5,9};
    Node* root=sortedToBST(arr);
    preorder(root);
}