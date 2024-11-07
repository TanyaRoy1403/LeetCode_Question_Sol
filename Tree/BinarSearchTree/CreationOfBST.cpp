#include <iostream>
#include <vector>
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

// Function to insert a node in BST
Node* insertNode(Node* root, int val) {
    if (root == NULL) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insertNode(root->left, val);
    } else if (val > root->data) {
        root->right = insertNode(root->right, val);
    }
    return root;
}

// Function to create BST from a vector of inputs
Node* creationBST(Node* root, vector<int>& input) {
    for (int i = 0; i < input.size(); i++) {
        root = insertNode(root, input[i]);
    }
    return root;
}

// Helper function to perform inorder traversal and print the tree
void printBST(Node* root) {
    if (root == NULL) {
        return;
    }
    printBST(root->left);
    cout << root->data << " ";
    printBST(root->right);
}

int main() {
    Node* root = NULL;
    vector<int> input = {10, 5, 15, 3, 7, 13, 17};
    
    root = creationBST(root, input);
    
    // Print inorder traversal of the BST
    cout << "Inorder Traversal of BST: ";
    printBST(root);
    
    return 0;
}
