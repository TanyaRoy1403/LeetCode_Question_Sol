#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/*You are given the head of a linked list with n nodes.

For each node in the list, find the value of the next greater node. That is, for each node, 
find the value of the first node that is next to it and has a strictly larger value than it.

Return an integer array answer where answer[i] is the value of the next greater node of the ith node (1-indexed). 
If the ith node does not have a next greater node, set answer[i] = 0.*/
class Node {
public:
    int data;
    Node* next;
    Node(int value) {
        this->data = value;
        this->next = NULL;
    }
};

Node* insert_end(int value, Node*& head) {
    Node* newNode = new Node(value);
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    return head;
}

void nextGreaterele(vector<int>& arr, vector<int>& nextAns) {
    stack<int> st;
    for (int i = arr.size() - 1; i >= 0; i--) {
        int curr_ele = arr[i];
        while (!st.empty() && st.top() <= curr_ele) {
            st.pop();
        }
        if(!st.empty()){
        nextAns[i] = st.top();
        }
        st.push(curr_ele);
    }
}

vector<int> solve(Node* head) {
    vector<int> ans;
    while (head) {
        ans.push_back(head->data);
        head = head->next;
    }
    
    vector<int> result(ans.size(), 0); // Initialize the result vector with the same size as ans
    nextGreaterele(ans, result);
    
    return result;
}

int main() {
    Node* head = NULL;
    insert_end(2, head);
    insert_end(7, head);
    insert_end(4, head);
    insert_end(3,head);
    insert_end(5,head);
    
    vector<int> ans = solve(head);
    for (auto& ch : ans) {
        cout << ch << " ";
    }
    cout << endl;
    
    return 0;
}
