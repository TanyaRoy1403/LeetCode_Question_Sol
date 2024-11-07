#include<iostream>
#include<vector>
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

Node* solve(vector<int>&inorder,vector<int>&postorder,int startIn,int endIn,int &postind){
    //base case
    if(startIn>endIn){
        return NULL;
    }
    //root ka value nikalo
    int rootval=postorder[postind]; //postorder me ka last value

    int i=startIn;
    for(;i<endIn;i++){
        if(inorder[i]==rootval){
            break;
        }
    }
    postind--;

    //root buil krege

    Node* root=new Node(rootval);

    //inorder me se jo left and right subttree milega usme postorder lagyege

    root->right=solve(inorder,postorder,i+1,endIn,postind);
    root->left=solve(inorder,postorder,startIn,i-1,postind);

    return root;
}

Node* buildBT(vector<int>inorder,vector<int>postorder){
    int n=postorder.size();
    int postind=n-1;
    return solve(inorder,postorder,0,n-1,postind);

}
void printPre(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    printPre(root->left);
    printPre(root->right);
}

int main() {
    vector<int> inorder = {9,3,15,20,7};
   vector<int>postorder={9,15,7,20,3};
    
    Node* root = buildBT(inorder,postorder);
    
    cout << "Preorder Traversal of Constructed Tree: ";
    printPre(root);
    cout << endl;
    
    return 0;
}
