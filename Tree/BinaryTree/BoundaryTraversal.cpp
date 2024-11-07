#include<iostream>
#include<vector>
#include<queue>
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

//traverse left part of BT

void leftpart(Node* root,vector<int>&ans){
    //base case
    if((root==NULL)||(root->left==NULL&&root->right==NULL)){
        return ;
    }
    //agr left part exit kr rha h to
    ans.push_back(root->data);
    if(root->left!=NULL){
        leftpart(root->left,ans);
    }
    //agr nhi kr rha h tb right me chleye jayegr
    else{
        leftpart(root->right,ans);
    }
}

//ab leaves node ko traversa

void leavespart(Node* root,vector<int>&ans){
    //base case
    if(root==NULL){
        return ;
    }
    if(root->left==NULL&&root->right==NULL){
        ans.push_back(root->data);
        return;
    }
    leavespart(root->left,ans);
    leavespart(root->right,ans);
}

//ab right part

void rightpart(Node* root,vector<int>&ans){
    //base case
    if((root==NULL)||(root->left==NULL&&root->right==NULL)){
        return ;
    }
    if(root->right!=NULL){
        rightpart(root->right,ans);
    }
    else{
        rightpart(root->left,ans);
    }
    ans.push_back(root->data);
}

vector<int> boundaryTra(Node*root){
    vector<int>ans;
    if(root==NULL){
        return ans;
    }
    ans.push_back(root->data);
    leftpart(root->left,ans);
    leavespart(root->left,ans);
    leavespart(root->right,ans);
    rightpart(root->right,ans);
    return ans;
}
int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->left->right->left=new Node(8);
    root->left->right->right=new Node(9);

    root->right->left=new Node(6);
    root->right->right=new Node(7);

    vector<int>ans=boundaryTra(root);
    for(auto& ch:ans){
        cout<<ch<<" ";
    }
    return 0;
}