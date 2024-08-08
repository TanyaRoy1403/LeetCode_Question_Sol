#include<iostream>
#include<vector>
using namespace std;

/*You are given two integers m and n, which represent the dimensions of a matrix.

You are also given the head of a linked list of integers.

Generate an m x n matrix that contains the integers in the linked list presented in spiral order (clockwise), 
starting from the top-left of the matrix. If there are remaining empty spaces, fill them with -1.

Return the generated matrix.*/

class Node{
    public:
    int data;
    Node* next;
    Node(int value){
        this->data=value;
        this->next=NULL;
    }

};
Node* insert_end(int value,Node*& head){
        Node* newNode=new Node(value);
        if(head==NULL){
            head=newNode;
        }else{
            Node* temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newNode;
            newNode->next=NULL;
        }
    return head;
}
void printll(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
}

vector<vector<int>> spiral_matrix(int m, int n, Node*& head){
    vector<vector<int>>ans(m,vector<int>(n,-1));
    int top_row=0;
    int down_row=m-1;
    int first_col=0;
    int last_col=n-1;
    int direction=0;
    Node* temp=head;
    while(top_row <= down_row && first_col <= last_col && temp != NULL){
        if(direction==0){
             for (int i = first_col; i <= last_col && temp != NULL; i++) {
                ans[top_row][i] = temp->data;
                temp=temp->next;
            }
            top_row++;
        }
        else if (direction == 1) {  // Move top to bottom
            for (int i = top_row; i <= down_row  && temp != NULL; i++) {
                ans[i][last_col] = temp->data;
                temp=temp->next;
            }
            last_col--;  // move the last column left
        } 
        else if (direction == 2) {  // Move right to left
            for (int i = last_col; i >= first_col  && temp != NULL; i--) {
                ans[down_row][i] = temp->data;
                temp=temp->next;
            }
            down_row--;  // move the bottom row up
        } 
        else if (direction == 3) {  // Move bottom to top
            for (int i = down_row; i >= top_row && temp != NULL; i--) {
                ans[i][first_col] = temp->data;
                temp=temp->next;
            }
            first_col++;  // move the first column right
        }
        direction = (direction + 1) % 4;
    }
    return ans;
}

int main(){
    Node* head=NULL;
    insert_end(3,head);
    insert_end(0,head);
    insert_end(2,head);
    insert_end(6,head);
    insert_end(8,head);
    insert_end(1,head);
    insert_end(7,head);
    insert_end(9,head);
    insert_end(4,head);
    insert_end(2,head);
    insert_end(5,head);
    insert_end(5,head);
    insert_end(0,head);
    insert_end(1,head);
    int m=3;
    int n=5;
    vector<vector<int>>ans=spiral_matrix(m,n,head);
       for (const auto& row : ans) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }

}