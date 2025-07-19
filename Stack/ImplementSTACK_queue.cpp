#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Mystack{
    public:
    queue<int>q1; //main queue
    queue<int>q2; //helper queue
    int size;
    Mystack(){
        size=0;
    }
    void push(int value){
        q1.push(value);
        size++;

    }
    int pop(){
        if(size==0)return -1;
        while(q1.size()>1){
            int firstele=q1.front(); //q1 ke sare ele q2 me push kr do except last ko (jo ki stack ka top hoga)
            q2.push(firstele);
            q1.pop();
        }
        int lastele=q1.front();
        q1.pop();
        size--;
        swap(q1,q2); //kyu ki ab to sare ele q2 me aa gya h islye q2 ab main queue hoga or q1 as helper queue
        return lastele;
    
    }
    int top(){
        if(size==0)return -1;
        while(q1.size()>1){
            int ele=q1.front();
            q2.push(ele);
            q1.pop();
        }
        int topele=q1.front();
        q1.pop();
        q2.push(topele);
        swap(q1,q2);
        return topele;

    }
    bool empty(){
        return size==0;

    }
};
//using one queue only
class MyStack{
    public:
    queue<int>q;
    int size;
    MyStack(){
        size=0;

    }
    void push(int val){
        q.push(val);
        for(int i=0;i<size;i++){
            int firstele=q.front();
            q.push(firstele);  //val se phele jitne v element h sb ko piiche se push kr do(simply push) now val become front element
            q.pop();
        }
        size++;

    }
    int pop(){
        if(size==0)return -1;
        int poppedele=q.front();
        q.pop();
        size--;
        return poppedele;

    }
    int top(){
        return q.front();

    }
    bool empty(){
        return size==0;

    }
};
int main(){
    Mystack* obj=new Mystack();
    obj->push(1);
    obj->push(2);
    int ans=obj->top();
    int res=obj->pop();
    bool an=obj->empty();
    cout<<"Uisng double queue:"<<" ";
    cout<<ans<<" "<<res;
    cout<<(an?"true":"false");
    cout<<endl;
    MyStack* obje=new MyStack();
    obje->push(1);
    obje->push(2);
    int ans1=obje->top();
    int res1=obje->pop();
    bool an1=obje->empty();
    cout<<endl;
    cout<<"using single queue:"<<" ";
    cout<<ans1<<" "<<res1;
    cout<<" ";
    cout<<(an1?"true":"false");


}