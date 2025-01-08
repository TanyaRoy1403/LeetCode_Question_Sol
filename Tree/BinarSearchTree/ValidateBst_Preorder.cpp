#include<iostream>
#include<vector>
#include<climits>
#include<stack>
#include<queue>
#include<cmath>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set> 
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
