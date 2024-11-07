
#include<iostream>
#include<vector>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;
    
    Node(int value) {
        this->data = value;
        left = NULL;
        right = NULL;
    }
};

// Helper function to build the tree
Node* solve(vector<int>& preOrder, vector<int>& InOrder, int start, int end, int& rootIdx) {
    // Base case
    if (start > end) {
        return NULL;
    }
    
    // Root value from preOrder
    int rootVal = preOrder[rootIdx];
    
    // Find the root value in InOrder
    int i = start;
    for (; i <= end; i++) {
        if (InOrder[i] == rootVal) {
            break;
        }
    }
    
    // Update rootIdx for the next recursive call
    rootIdx++;
    
    // Create the root node
    Node* root = new Node(rootVal);
    
    // Recursively build the left and right subtrees
    root->left = solve(preOrder, InOrder, start, i - 1, rootIdx);
    root->right = solve(preOrder, InOrder, i + 1, end, rootIdx);
    
    return root;
}

// Main function to build tree
Node* buildTree(vector<int>& preOrder, vector<int>& InOrder) {
    int n = preOrder.size();
    int rootIdx = 0;
    return solve(preOrder, InOrder, 0, n - 1, rootIdx);
}

// Function to print the inorder traversal of the tree
void printInOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    printInOrder(root->left);
    printInOrder(root->right);
}

int main() {
    vector<int> preOrder = {3,9,20,15,7};
    vector<int> InOrder = {9,3,15,20,7};
    
    Node* root = buildTree(preOrder, InOrder);
    
    cout << "InOrder Traversal of Constructed Tree: ";
    printInOrder(root);
    cout << endl;
    
    return 0;
}
