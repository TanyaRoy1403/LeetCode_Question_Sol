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

//mera socha hua approach
//inorder must be sorted

void inorder(Node*root,vector<int>&arr){
    if(root==NULL){
        return ;
    }
    inorder(root->left,arr);
    arr.push_back(root->data);
    inorder(root->right,arr);
}

bool valideBst(Node*root){
    vector<int>arr;
    inorder(root,arr);
    for(int i=1;i<arr.size();i++){
        if(arr[i]<=arr[i-1]){
            return false;
        }
    }
    return true;
}
//time complexity:O(n)
//space complexityO(n)


//method 2
//we can optimise in term of space ...we use prev pointer to keep track of prev value and keep this upadating afetr comparing with root value

bool  inorder2(Node* root,Node*& prev){
    if(root==NULL){
        return true ;
    }
    //left tarvers
    bool leftside=inorder2(root->left,prev);
    if(!leftside){
        return false;
    }
   
    if(prev&&root->data<=prev->data){
            return false;
    }
        
    prev=root;
    bool rightside=inorder2(root->right,prev);
    if(!rightside){
        return false;;
    }
    return true;
}

bool validatebst(Node*root){
    Node* prev=NULL;
    return inorder2(root,prev);
}

//method 3 standard method using range
bool validate3(Node*root, long long lb, long long ub){
        if(!root) return true;

        bool isCurrentNodeInRange = root->data > lb && root->data < ub;
        bool isLeftBST = true;
        bool isRightBST = true;
        if(isCurrentNodeInRange) {
            isLeftBST = validate3(root->left, lb, root->data);
            isRightBST = validate3(root->right, root->data, ub);
        }

        return isCurrentNodeInRange && isLeftBST && isRightBST;
}


bool isValidBST(Node* root) {
    long long lb = LONG_MIN, ub = LONG_MAX;
    return validate3(root, lb, ub);
}
int main(){
    Node* root=new Node(5);
    root->left=new Node(1);
    root->right=new Node(4);
    root->right->left=new Node(3);
    root->right->right=new Node(6);

    bool result=valideBst(root);
    if(result){
        cout<<"Tree is BST"<<endl;
    }
    else{
        cout<<"Tree is not BST"<<endl;
    }
    cout<<endl;

        bool result2=validatebst(root);
    if(result2){
        cout<<"Tree is BST"<<endl;
    }
    else{
        cout<<"Tree is not BST"<<endl;
    }

}
int main(){

}