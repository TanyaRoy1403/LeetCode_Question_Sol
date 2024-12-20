#include<iostream>
#include<vector>
#include<climits>
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

void solve(Node* root,int &ans,Node* &prev){
    if(root==NULL){
        return ;
    }
    //inorder
    solve(root->left,ans,prev);
    //ab condition lga ke ans nikalyege
    if(prev){
        ans=min(ans,root->data- prev->data);
        //update prev
        prev=root;
    }
    //right ko call
    solve(root->right,ans,prev);
}
int MinDiff(Node* root){
    int ans=INT_MAX;
    Node* prev=NULL;
    solve(root,ans,prev);
    return ans;
}
int main(){
   
}