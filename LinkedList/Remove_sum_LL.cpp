#include<iostream>
#include<unordered_map>
using namespace std;

/*Given the head of a linked list, we repeatedly delete consecutive sequences of nodes that sum to 0 until there are no such sequences.

After doing so, return the head of the final linked list.  You may return any such answer.

 

(Note that in the examples below, all sequences are serializations of Node objects.)*/

class Node{
    public:
    int data;
    Node* next;
    Node(int value){
        this->data=value;
        this->next=NULL;
    }
};


void printll(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<"NULL";
}
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

//prefixsum ko bdna chiya tha but kisi ke point pe ght gya mtlb use neagtive number add hua hoga tb na to summ zero v ho skta h
Node* remove_sum_zero(Node*& head){
    int pre_sum=0;
    unordered_map<int,Node*>mp;
    //dummy node create
    Node* dummy=new Node(0);
    dummy->next=head;
    mp[0]=dummy;
    while(head){
        pre_sum+=head->data;
        if(mp.find(pre_sum)!=mp.end()){  //agr pre_sum mil gya map mtlb sum zero hua hoga waha tk ka
            
            //deletion
            Node* start=mp[pre_sum];  // pheli baar kaha dekha tha waha chl gya
            Node* temp=start; //to trverse
            int curr_preSum=pre_sum;
            while(temp!=head){  //head ko curr maan lo
                temp=temp->next;
                //update curr_preSum
                curr_preSum+=temp->data;
                if(temp!=head){
                  //map se dlete kro
                  mp.erase(curr_preSum);
                }
                //bache hue to link kr do
                start->next=head->next;  //kyu head ek delted node pe khda h non dlete node se ek phle(head negative no pe khda hoga)
            }
        }else{  //nhi mila to map me add kr do
            mp[pre_sum]=head;
        }
        head=head->next;
    }
    return dummy->next;
}
int main(){
    Node* head=NULL;
    insert_end(1,head);
    insert_end(2,head);
    insert_end(-3,head);
    insert_end(3,head);
    insert_end(1,head);
    Node* newHead=remove_sum_zero(head);
    printll(newHead);
}