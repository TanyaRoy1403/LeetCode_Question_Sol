#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
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

void solveLeft(Node* root,int level,vector<int>&ans){
    if(root==NULL){
        return ;
    }
    if(level==ans.size()){
        ans.push_back(root->data);
    }
    solveLeft(root->left,level+1,ans);
    solveLeft(root->right,level+1,ans);
}
vector<int> LeftView(Node* root){
    vector<int>ans;
    int level=0;
    solveLeft(root,level,ans);
    return ans;
}


void solveRight(Node* root,int level,vector<int>&ans){
    if(root==NULL){
        return ;
    }
    if(level==ans.size()){
        ans.push_back(root->data);
    }
    solveRight(root->right,level+1,ans);
    solveRight(root->left,level+1,ans);
}
vector<int> RightView(Node* root){
    vector<int>ans;
    int level=0;
    solveRight(root,level,ans);
    return ans;
}
vector<int> TopView(Node* root){
    queue<pair<Node*, int>>q; //node along with theirs horizontal distance
    q.push(make_pair(root,0));
    unordered_map<int ,Node*>distMap;
    int max_dist=INT_MIN;
    int min_dist=INT_MAX;
    while(!q.empty()){
        //level order
        pair<Node*,int>temp=q.front();
        q.pop();
        Node* fronNode=temp.first;
        int hd=temp.second;
        max_dist=max(max_dist,hd);
        min_dist=min(min_dist,hd);
        if(distMap.find(hd)==distMap.end()){
            distMap[hd]=fronNode;
        }
        if(fronNode->left!=NULL){
            q.push(make_pair(fronNode->left,hd-1));
        }if(fronNode->right!=NULL){
            q.push(make_pair(fronNode->right,hd+1));
        }
    }
    vector<int>ans;
    for(int i=min_dist;i<=max_dist;i++){
        Node* temp=distMap[i];
        ans.push_back(temp->data);
    }
    return ans;


}

vector<int> BottomView(Node* root){
    queue<pair<Node*, int>>q; //node along with theirs horizontal distance
    q.push(make_pair(root,0));
    unordered_map<int ,Node*>distMap;
    int max_dist=INT_MIN;
    int min_dist=INT_MAX;
    while(!q.empty()){
        //level order
        pair<Node*,int>temp=q.front();
        q.pop();
        Node* fronNode=temp.first;
        int hd=temp.second;
        max_dist=max(max_dist,hd);
        min_dist=min(min_dist,hd);
        if (distMap.find(hd) == distMap.end()) {
          distMap[hd] = fronNode;
    }

        if(fronNode->left!=NULL){
            q.push(make_pair(fronNode->left,hd-1));
        }if(fronNode->right!=NULL){
            q.push(make_pair(fronNode->right,hd+1));
        }
    }
    vector<int>ans;
    for(int i=min_dist;i<=max_dist;i++){
        Node* temp=distMap[i];
        ans.push_back(temp->data);
    }
    return ans;


}
int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->right=new Node(5);
    root->left->left=new Node(4);
    root->left->left->right=new Node(8);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    cout<<"Left view:"<<" ";
    vector<int>ans=LeftView(root);
    for(auto&ch:ans){
        cout<<ch<<" ";
    }
    cout<<endl;
    cout<<"Right view:"<<" ";
    vector<int>ans3=RightView(root);
    for(auto&ch:ans3){
        cout<<ch<<" ";
    }
    cout<<endl;
    cout<<"Top view:"<<" ";
    vector<int>ans1=TopView(root);
    for(auto&ch:ans1){
        cout<<ch<<" ";
    }
    cout<<endl;
    cout<<"Bottom view:"<<" ";
    vector<int>ans2=BottomView(root);
    for(auto&ch:ans2){
        cout<<ch<<" ";
    }



}