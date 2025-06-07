#include<iostream>
#include<vector>
#include<map>
#include<queue>
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


vector<vector<int>> VerticalOrder(Node* root) {
    if (!root) return {};

    map<int, vector<int>> hdMap;  // HD -> list of nodes
    queue<pair<Node*, int>> q;    // {Node, HD}
    q.push(make_pair(root, 0));

    while (!q.empty()) {
        pair<Node*, int> temp = q.front();
        q.pop();

        Node* node = temp.first;
        int hd = temp.second;

        hdMap[hd].push_back(node->data);

        if (node->left)
            q.push(make_pair(node->left, hd - 1));
        if (node->right)
            q.push(make_pair(node->right, hd + 1));
    }

    vector<vector<int>> result;
    for (auto it = hdMap.begin(); it != hdMap.end(); ++it) {
        result.push_back(it->second);
    }

    return result;
}


void verticalTra(Node* root,int hd,map<int,vector<int>>&mp){
    if(root==NULL){
        return ;
    }
    mp[hd].push_back(root->data);
    verticalTra(root->left,hd-1,mp);
    verticalTra(root->right,hd+1,mp);
    
}
vector<int> verticalTravesal(Node* root) {
    map<int, vector<int>> mp;
    verticalTra(root, 0, mp);

    vector<int> result;
    for (auto it : mp) {
        result.insert(result.end(), it.second.begin(), it.second.end());
    }
    return result;
}


int main(){
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);  
    root->right->right=new Node(7);
    root->right->left->right=new Node(8);
    root->right->right->right=new Node(9);

    // map<int, vector<int>> mp;
    // verticalTra(root, 0, mp);

    // // Printing the vertical order traversal
    // for (auto it : mp) {
    //     for (int node : it.second) {
    //         cout << node << " ";
    //     }
    //     cout << endl;
    // }
    vector<int>ans=verticalTravesal(root);
    for(auto&ch:ans){
        cout<<ch<<" ";
    }
    cout<<endl;
    vector<vector<int>>res=VerticalOrder(root);
   cout << "Vertical Order Traversal:\n";
    for (const auto& col : res) {
        for (int val : col) {
            cout << val << " ";
        }
        cout << endl;
    }

}