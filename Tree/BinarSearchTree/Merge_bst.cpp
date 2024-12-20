#include<iostream>
#include<vector>
#include<stack>
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
vector<int> mergeBST(Node*root1,Node*root2){
    vector<int>ans;
    stack<Node*>st1,st2;
    Node*a=root1,*b=root2;
    while(a||b||!st1.empty()||!st2.empty()){
        while(a){
            st1.push(a);
            a=a->left;
        }
        while(b){
            st2.push(b);
            b=b->left;
        }
        if(st2.empty()||(!st1.empty()&&st1.top()->data<=st2.top()->data)){
            auto top1=st1.top();
            ans.push_back(top1->data);
            st1.pop();
            a=top1->right;
        }else{
            auto top2=st2.top();
            st2.pop();
            ans.push_back(top2->data);
            b=top2->right;
        }
    }
    return ans;
}
int main(){
    Node*root1=new Node(5);
    root1->left=new Node(3);
    root1->right=new Node(6);
    root1->left->left=new Node(2);
    root1->left->right=new Node(4);

    Node*root2=new Node(2);
    root2->left=new Node(1);
    root2->right=new Node(3);
    root2->right->right=new Node(7);
    root2->right->right->left=new Node(6);

    vector<int>ans=mergeBST(root1,root2);
    for(auto&ch:ans){
        cout<<ch<<" ";
    }
}
