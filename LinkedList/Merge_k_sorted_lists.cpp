#include<iostream>
#include<vector>
#include<queue>
using namespace std;

 class Node{
    public:
    int data;
    Node* next;
    Node(int value){
        this->data=value;
        this ->next=NULL;
    }

};
class compare
{
public:
bool operator()(Node* a, Node* b){
    return a->data >b->data;

}
};
//uisng heap, tc: O(nlog k), sc: O(k)
Node* mergeLists(vector<Node*>arr){
    priority_queue<Node* ,vector<Node*>, compare>hp;
    //push all head into heap
    for(auto it:arr){
        if(it){
        hp.push(it);}
    }
    //build final sorted list 
    Node* dummy=new Node(0);
    Node* tail=dummy;
    while(!hp.empty()){
        Node* smallest=hp.top();
        hp.pop();
        tail->next=smallest;
        tail=tail->next;
        if(smallest->next){
            hp.push(smallest->next);
        }
    }
    return dummy->next;
    
}
//using merge sort + recursion
int main() {
    // Suppose you have k lists like:
    // list1: 1 -> 4 -> 5
    // list2: 1 -> 3 -> 4
    // list3: 2 -> 6

    Node* l1 = new Node(1);
    l1->next = new Node(4);
    l1->next->next = new Node(5);

    Node* l2 = new Node(1);
    l2->next = new Node(3);
    l2->next->next = new Node(4);

    Node* l3 = new Node(2);
    l3->next = new Node(6);

    vector<Node*> lists = {l1, l2, l3};

    
    Node* merged = mergeLists(lists);

    // Print merged list
    while (merged) {
        cout << merged->data << " ";
        merged = merged->next;
    }
    return 0;
}
