#include<iostream>
#include<vector>
#include<algorithm>
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

void preOdere(Node* root){
    // vector<int>ans;
    Node* currNode=root;
    while(currNode){
        //left child nhi h currNode ka
        if(currNode->left==NULL){
            cout<<currNode->data<<" ";
            currNode=currNode->right;
        }else{
            Node* temp=currNode->left;
            while(temp->right!=NULL&& temp->right!=currNode){
                temp=temp->right;
            }
            if(temp->right==NULL){
                temp->right=currNode;
                cout<<currNode->data<<" ";
                currNode=currNode->left;
            }else{
                temp->right=NULL;
                currNode=currNode->right;
            }
        }
    } 
}
void InOrder(Node* root){
    Node* currNode=root;
    while(currNode){
        if(currNode->left==NULL){
            cout<<currNode->data<<" ";
            currNode=currNode->right;
        }else{
            Node* temp=currNode->left;
            while(temp->right!=NULL&& temp->right!=currNode){
                temp=temp->right;
            }
            //link create kro
            temp->right=currNode;
            //link break kr do
            Node* tem=currNode;
            currNode=currNode->left;
            tem->left=NULL;
        }
    }
}

   vector<int> postOrder(Node* root) {
        // code here
        vector<int>ans;
        while(root){
            // left part doesn't exist
            if(!root->right){
                ans.push_back(root->data);
                root=root->left;
            }
            
            // left part exist
            else{
                Node*curr=root->right;
                
                while(curr->left && curr->left!=root)
                curr=curr->left;
                
                // left subtree not traverse
                if(curr->left==NULL){
                    ans.push_back(root->data);
                    curr->left=root;
                    root=root->right;
                }
                
                // already exist
                else{
                    curr->left=NULL;
                    root=root->left;
                }
            }
        }
         reverse(ans.begin(),ans.end());
         return ans;
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
    cout<<"preOrder is:"<<" ";
    preOdere(root);
    cout<<endl;
    cout<<"InOrder is:"<<" ";
    InOrder(root);
    cout<<endl;
    cout<<"Postorder is:"<<" ";
    vector<int>ans=postOrder(root);
    for(auto&ch:ans){
        cout<<ch<<" ";
    }
    
return 0;
}