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
vector<int> diagonal_tra(Node* root){
    vector<int>ans;
    queue<Node*>que;
    if(root==NULL){
        return ans;
    }
    que.push(root);
    while(!que.empty()){
        Node* temp=que.front();
        que.pop();
        while(temp){
            if(temp->left!=NULL)
            que.push(temp->left);
            ans.push_back(temp->data);
            temp=temp->right;
        }

    }
    return ans;
}
int main(){
    Node* root=new Node(8);
    root->left=new Node(3);
    root->right=new Node(10);
    root->left->left=new Node(1);
    root->left->right=new Node(6);
    root->left->right->left=new Node(4);
    root->left->right->right=new Node(7);

    root->right->right=new Node(14);
    root->right->right->left=new Node(13);
    vector<int>ans=diagonal_tra(root);
    for(auto &ch:ans){
        cout<<ch<<" ";
    }
    return 0;

}