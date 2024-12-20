#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

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
//we can use separte function to populate the map

// void populateMap(Node* root, unordered_map<int, bool>& mp) {
//     if (root == NULL) return;
//     mp[root->data] = true;
//     populateMap(root->left, mp);
//     populateMap(root->right, mp);
// }

void solve(Node*root,bool &ans,unordered_map<int,bool>&mp){
    if(root==NULL){
        return ;
    }
    //to handle edge case
    mp[0]=true;
    mp[root->data]=true;
    //leaf node
    if(root->left==NULL&&root->right==NULL){
        int xplus=root->data+1;
        int xminus=root->data-1;
        if(mp.find(xplus)!=mp.end()&&mp.find(xminus)!=mp.end()){
            ans=true;
            return;
        }
    }
    solve(root->left,ans,mp);
    solve(root->right,ans,mp);

}
bool isDeadEnd(Node*root){
    bool ans=false;
    unordered_map<int,bool>mp;
    solve(root,ans,mp);
    return ans;
}
int main(){
    Node*root=new Node(8);
    root->left=new Node(5);
    root->right=new Node(9);
    root->left->left=new Node(2);
    root->left->left->left=new Node(1);
    root->left->right=new Node(7);
    bool res=isDeadEnd(root);
    if(res){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
}