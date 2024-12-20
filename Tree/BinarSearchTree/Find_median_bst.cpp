#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node*right;
    Node(int value){
        this->data=value;
        left=NULL;
        right=NULL;
    }
};

int countNode(Node*root){
    if(root==NULL){
        return 0;
    }
    int count=0;
    Node*curr=root;
    while(curr){
        if(curr->left==NULL){
            count++;
            curr=curr->right;
        }
        else{
            //store left
            Node*pred=curr->left;
            while(pred->right!=NULL&&pred->right!=curr){
                pred=pred->right;
            }
            if(pred->right==NULL){
                pred->right=curr;
                curr=curr->left;
            }else{
                pred->right=NULL;
                count++;
                curr=curr->right;
            }
        }
    }
    return count;
}
float findActualMead(Node*root,int n){
    int i=0;
    int odd1=(n+1)/2,odd1val=-1;
    int even1=(n/2),even1val=-1;
    int even2=(n/2)+1,even2val=-1;
    Node*curr=root;
    while(curr){
        if(curr->left==NULL){
            i++;
            if(i==odd1) odd1val=curr->data;
            if(i==even1)even1val=curr->data;
            if(i==even2)even2val=curr->data;
            curr=curr->right;
        }
        else{
            //store left
            Node*pred=curr->left;
            while(pred->right!=NULL&&pred->right!=curr){
                pred=pred->right;
            }
            if(pred->right==NULL){
                pred->right=curr;
                curr=curr->left;
            }else{
                pred->right=NULL;
                i++;
                if(i==odd1) odd1val=curr->data;
                if(i==even1)even1val=curr->data;
                if(i==even2)even2val=curr->data;
                curr=curr->right;
            }
        }
    }
    float med=0;
    if(n&1==0){
        //even
        med=(even1val+even2val)/2.0;
    }else{
        //odd
        med=odd1val;
    }
    return med;
}
float mainFun(Node*root){
    int n=countNode(root);
    return findActualMead(root,n);
}

int main(){
    Node* root=new Node(6);
    root->left=new Node(3);
    root->right=new Node(8);
    root->left->left=new Node(1);
    root->left->right=new Node(4);
    root->right->left=new Node(7);
    root->right->right=new Node(9);
    float res=mainFun(root);
    cout<<"Median of given BST is:"<<res<<endl;

}