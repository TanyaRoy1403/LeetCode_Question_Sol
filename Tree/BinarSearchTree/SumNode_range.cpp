#include<iostream>
#include<vector>
using namespace std;

//938
class Node{
    public:
    int data;
    Node*left;
    Node*right;
    Node(int value){
        this->data=value;
        left=NULL;
        right=NULL;
    }
};

int SumNodeInRange(Node*root,int high,int low){
    if(root==NULL){
        return 0;
    }
    int sum=0;
    if(root->data<=high&&root->data>=low){
        sum+=root->data;
        sum+=SumNodeInRange(root->left,high,low);
        sum+=SumNodeInRange(root->right,high,low);
    }else if(root->data<low){
        sum+=SumNodeInRange(root->right,high,low);
    }else{
        sum+=SumNodeInRange(root->left,high,low);
    }
    return sum;  
}
int main(){
    Node*root=new Node(10);
    root->left=new Node(5);
    root->right=new Node(15);
    root->left->right=new Node(7);
    root->left->left=new Node(3);
    root->right->right=new Node(18);
    cout<<SumNodeInRange(root,15,7);
}