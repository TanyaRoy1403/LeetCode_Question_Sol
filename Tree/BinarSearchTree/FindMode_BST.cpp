#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//time complexity:O(n) spacecomplexuty O(n)
//Mode : the most frequently occurred element
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

void dfs(Node*root,unordered_map<int,int>&mp){
    if(!root)return ;
    //LNR
    dfs(root->left,mp);
    mp[root->data]++;
    dfs(root->right,mp);
}

vector<int>findMode(Node* root){
    unordered_map<int ,int>mp;
    dfs(root,mp);
    vector<int>ans;
    int maxFreq=0;
    for(auto it:mp){
        if(it.second>maxFreq){
            maxFreq=it.second;
            ans={};
            ans.push_back(it.first);
        }else if(it.second==maxFreq){
            ans.push_back(it.first);
        }
        
    }
    return ans;

}

int main(){
    Node* root=new Node(1);
    root->right=new Node(2);
    root->right->left=new Node(1);
    vector<int>res=findMode(root);
    for(auto it:res){
        cout<<it<<" ";
    }

}