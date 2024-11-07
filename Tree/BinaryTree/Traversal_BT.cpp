#include<iostream>
#include<vector>
#include<stack>
#include<deque>
#include<queue>
using namespace std;

//preorder traversal
//NLR (currNode,left,right)

class Node{
    public:
    int data;
    Node* leftChild;
    Node* rightChild;
    Node(int value){
        this->data=value;
        leftChild=NULL;
        rightChild=NULL;
    }
};
//using recursion
void preOder(Node* root){
    if(root==NULL){
        return;
    }
    //currNode
    cout<<root->data<<" ";
    //left Subtree
    preOder(root->leftChild);
    //right subtree
    preOder(root->rightChild);
}
//using loop
void solve(Node* root){
    // vector<int>result;
    stack<Node*>st;
    st.push(root);
    while(!st.empty()){
        Node* currNode=st.top();
        st.pop();
        cout<<currNode->data<<" ";
        //push right child first do that left will be at top
        if(currNode->rightChild){
          st.push(currNode->rightChild);
        }
        if(currNode->leftChild){
          st.push(currNode->leftChild);
        }
    }
}
//using recursion 
void inOrder(Node* root){
    //LNR
    if(root==NULL){
        return ;
    }
    //left subtree
    inOrder(root->leftChild);
    //N currNode
    cout<<root->data<<" ";
    //right sub tree
    inOrder(root->rightChild);
}
//using loop 
void solve2(Node* root){
    if(root==NULL){
        return;
    }
    //LNR
    stack<Node*>st;
    Node* currNode=root;
    while(currNode!=NULL||!st.empty()){
        //traverse till leftmost subtree of currnode
        while(currNode!=NULL){
            st.push(currNode);
            currNode=currNode->leftChild;

        }
        //agr currNode null nikla
        currNode=st.top();
        st.pop();
        cout<<currNode->data<<" ";
        //ab right subtree
        currNode=currNode->rightChild;

    }
}
void postOrder(Node* root){
    //LRN
    if(root==NULL){
        return;
    }
    //left subtree
    postOrder(root->leftChild);
    //right sub tree
    postOrder(root->rightChild);
    //currNode
    cout<<root->data<<" ";
}
void LevelOrder(Node* root){
   
    if(root==NULL){
        return ;
    }
    queue<Node*>que;
    que.push(root );
    while (!que.empty())
    {
        int levelsize=que.size();
        
        for(int i=0;i<levelsize;i++){
            Node* temp=que.front();
            que.pop();
            cout<<temp->data<<" ";

            //if left subtree exit
            if(temp->leftChild!=NULL){
                que.push(temp->leftChild);
            }
            if(temp->rightChild!=NULL){
                que.push(temp->rightChild);
            }   
        }   
    }
}
void levelorder2(Node* root){
    if(root==NULL){
        return ;
    }
    queue<Node*>que;
    que.push(root);
    que.push(NULL);
    while(!que.empty()){
        Node* frontNode=que.front();
        que.pop();
        if(frontNode==NULL){
            cout<<endl;
            if(!que.empty()){
                que.push(NULL);
            }
        }else{
            cout<<frontNode->data<<" ";
            if(frontNode->leftChild!=NULL){
                que.push(frontNode->leftChild);
            }
            if(frontNode->rightChild!=NULL){
                que.push(frontNode->rightChild); 
            }
        }
    }

}
//height of tree
int heightTree(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftKaAns=heightTree(root->leftChild);
    int rightKaAns=heightTree(root->rightChild);
    return max(leftKaAns,rightKaAns)+1;
  
}
//check tree is balance or not
bool checkBalance(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftKaHeight=heightTree(root->leftChild);
    int rightKaHeight=heightTree(root->rightChild);
    int finalValue=abs(leftKaHeight-rightKaHeight);
    bool ans=(finalValue<=1);
    int leftka=checkBalance(root->leftChild);
    int rightka=checkBalance(root->rightChild);
    if(ans&&leftka&&rightka){
        return true;
    }
    return false;
    
}
void morris_traversal(Node*root){
    if(root==NULL){
        return;
    }
    Node* curr=root;
    while(curr){
        if(curr->leftChild==NULL){
            cout<<curr->data<<" ";
            curr=curr->rightChild;
        }else{
            Node* temp=curr->leftChild;
            while(temp){
                curr=curr->rightChild;
            }
        }
    }
    
}
int main(){
    Node* root= new Node(10);
    root->leftChild=new Node(20);
    root->rightChild=new Node(30);
    root->leftChild->leftChild=new Node(40);
    root->leftChild->rightChild=new Node(50);
    root->leftChild->leftChild->leftChild=new Node(80);
    root->rightChild->leftChild=new Node(60);
    root->rightChild->rightChild=new Node(70);
    root->rightChild->leftChild->rightChild=new Node(90);
    cout<<"PreOrder is: "<<" ";
    preOder(root);
    cout<<endl;
    cout<<"Preorder using loop"<<" ";
    solve(root);
    cout<<endl;
    cout<<"Inorder is:"<<" ";
    inOrder(root);
    cout<<endl;
    cout<<"Inorder using loop:"<<" ";
    solve2(root);
    cout<<endl;
    cout<<"PostOrder is:"<<" ";
    postOrder(root);
    cout<<endl;
    cout<<"Level order is:"<<" ";
    LevelOrder(root);
    cout<<endl;
    cout<<heightTree(root);
    cout<<endl;
    cout<<"level order 2 is:"<<" ";
    levelorder2(root);
    
    cout<<endl;
    bool ans=checkBalance(root);
    if(ans){
        cout<<"tree is balanced"<<endl;
    }
    else{
        cout<<"tree is not balanced"<<" ";
    }
    return 0;
}

