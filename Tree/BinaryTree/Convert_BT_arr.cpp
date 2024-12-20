#include <iostream>
#include <vector>
#include <queue>
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
vector<int> binaryTreeToArray(Node* root) {
    vector<int> result;
    if (root == NULL) {
        return result;
    }
    
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        
       //ab curr node ka data vector me add kr dete h
        result.push_back(current->data);
        
       //agrr curr node ka left ya right child h to queue me add kr do
        if (current->left) {
            q.push(current->left);
        }
        if (current->right) {
            q.push(current->right);
        }
    }

    return result;
}

int main(){
    Node* root= new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->left->left=new Node(40);
    root->left->right=new Node(50);
    root->left->left->left=new Node(80);
    root->right->left=new Node(60);
    root->right->right=new Node(70);
    root->right->left->right=new Node(90);
    vector<int>result=binaryTreeToArray(root);
    for(auto&it:result){
        cout<< it<<" ";
    }
}