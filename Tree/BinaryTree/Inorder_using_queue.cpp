#include <iostream>
#include <queue>
using namespace std;

// Definition for a Binary Tree Node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Inorder Traversal using Queue
void inorderTraversal(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    TreeNode* curr = root;

    // Step 1: Push all leftmost nodes into queue
    while (curr) {
        q.push(curr);
        curr = curr->left;
    }

    // Step 2: Process nodes in queue
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        // Print the current node (Root)
        cout << node->val << " ";

        // Step 3: If the node has a right subtree, enqueue its leftmost nodes
        curr = node->right;
        while (curr) {
            q.push(curr);
            curr = curr->left;
        }
    }
}

// Driver code
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    cout << "Inorder Traversal using Queue: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
//output: Inorder Traversal using Queue: 4 2 5 1 6 3 7
// Time Complexity: O(n)
// Space Complexity: O(n)
