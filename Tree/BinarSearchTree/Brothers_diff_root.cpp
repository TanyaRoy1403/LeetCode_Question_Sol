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
//brute force..time complexity--O(n1+n2), number of nodes in bst1 and bst2 ..space complexity--O(n1+n2)
void inorderStored(Node*root1,vector<int>&inor1){
    if(root1==NULL){
        return ;
    }
    inorderStored(root1->left,inor1);
    inor1.push_back(root1->data);
    inorderStored(root1->right,inor1);
}
void inorderRev(Node*root2,vector<int>&inor2){
    if(root2==NULL){
        return ;
    }
    inorderRev(root2->right,inor2);
    inor2.push_back(root2->data);
    inorderRev(root2->left,inor2);
}
int countPairs(Node*root1,Node*root2,int x){
    vector<int>inor1;
    vector<int>inor2;
    inorderStored(root1,inor1);
    inorderRev(root2,inor2);

    int i = 0, j = 0, count = 0;
    while (i < inor1.size() && j < inor2.size()) {
        int sum = inor1[i] + inor2[j];

        if (sum == x) {
            count++;
            i++; // Move to the next larger element in BST1
            j++; // Move to the next smaller element in BST2
        } else if (sum < x) {
            i++; // Sum is too small; move to the next larger element
        } else {
            j++; // Sum is too large; move to the next smaller element
        }
    }
    return count;
}

//optimal solution-->using stacks

int countpairs(Node*root1,Node*root2,int x){
    stack<Node*>st1,st2;
    Node* rt1=root1;
    Node* rt2=root2;
    int count=0;
    while(1){
        while(rt1){
            st1.push(rt1);
            rt1=rt1->left;
        }
        while(rt2){ 
            st2.push(rt2);
            rt2=rt2->right;
        }
        if(st1.empty()||st2.empty()){
            break;
        }
        int sum=rt1->data+rt2->data;
        if(sum==x){
            count++;
            st1.pop();
            st2.pop();
            rt1=rt1->right;
            rt2=rt2->left;
        }
        else if(sum<x){
            //mtlb jada chaiye ...st1 me se pop kryege taaki hme jada bda element mil skhe jo stack 1 ke bottom me h
            st1.pop();
            rt1=rt1->right;
        }else{
            st2.pop();
            rt2=rt2->left;
        }
    }
    return count;
}
int main(){
    Node* root=new Node(5);
    root->left=new Node(3);
    root->right=new Node(7);
    root->left->left=new Node(2);
    root->left->right=new Node(4);
    root->right->left=new Node(6);
    root->right->right=new Node(8);
    Node*root1=new Node(10);
    root1->left=new Node(6);
    root1->right=new Node(15);
    root1->left->left=new Node(3);
    root1->left->right=new Node(8);
    root1->right->left=new Node(11);
    root1->right->right=new Node(18);
    int result=countPairs(root,root1,16);
    cout<<"Piar is :"<<result;
    cout<<endl;
    int result2=countPairs(root,root1,16);
    cout<<"number of pairs is :"<<result2;



}