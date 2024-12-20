#include<iostream>
#include<vector>
#include<algorithm>
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
//brute force time complexity:O(n)+O(nlogn)
Node* solve(vector<int>&preorder,vector<int>&inorder,int start,int end,int& rootidx){
    if(start>end){
        return NULL ;
    }
    int rootvalue=preorder[rootidx];
    int i=start;
    while(i<=end){
        if(inorder[i]==rootvalue){
            break;
        }
        i++;
    }
    rootidx++;
    Node* root=new Node(rootvalue);

    root->left=solve(preorder,inorder,start,i-1,rootidx);
    root->right=solve(preorder,inorder,i+1,end,rootidx);
    return root;
}
Node* buldBST(vector<int>preorder){
    vector<int>inorder=preorder;
    sort(inorder.begin(),inorder.end());
    int n=preorder.size();
    int rootidx=0;
    int start=0;
    int end=n-1;
    return solve(preorder,inorder,start,end,rootidx);
}
Node* solve2(vector<int>&preorder,int& i,int min_range,int max_range){
    if(i>=preorder.size()){
        return NULL;
    }
    Node* root=NULL;
    if(preorder[i]>min_range&&preorder[i]<max_range){
        root=new Node(preorder[i]);
        i++;
        root->left=solve2(preorder,i,min_range,root->data);
        root->right=solve2(preorder,i,root->data,max_range);
    }
    return root;

}
Node* buildBST(vector<int>preorder){
    int min_range=INT_MIN;
    int max_range=INT_MAX;
    int i=0;
    return solve2(preorder,i,min_range,max_range);
}
void inorderTraversal(Node* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}
int main(){
    vector<int>preorder={8,5,1,7,10,12};
    Node* root=buldBST(preorder);
    inorderTraversal(root);
    cout<<endl;
    cout<<endl;
    Node* root2=buildBST(preorder);
    inorderTraversal(root2);

}