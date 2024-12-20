#include<iostream>
#include<stack>
#include<vector>
using namespace std;


//most important question 
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

class bstiterator{
    public:
    stack<Node*>st1,st2;
    //methods
    void pushleft(Node* root){
        while(root){
            st1.push(root);
            root=root->left;
        }
    }
    void pushright(Node* root){
        while(root){
            st2.push(root);
            root=root->right;
        }
    }


    bstiterator(Node*root){
        pushleft(root);
        pushright(root);

    }
    int next(){
        auto top=st1.top();
        st1.pop();
        if(top->right!=NULL){
            pushleft(top->right);
        }
        return top->data;
    }
    int prev(){
        auto top=st2.top();
        st2.pop();
        if(top->left!=NULL){
            pushright(top->left);
        }
        return top->data;
    }
    bool hasprev(){
        return !st2.empty();
    }
    bool hasnext(){
        return !st1.empty();

    }
};
