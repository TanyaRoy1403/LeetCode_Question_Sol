#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class RecentCounter {
public:
    queue<int>q;
    RecentCounter() {
    }
    int ping(int t) {
        int range=(t-3000);
        q.push(t);
        while(q.front()<range&&!q.empty()){
            q.pop();
        }
        return q.size();
    }
};
int main(){
    RecentCounter* obj = new RecentCounter();
    cout<<obj->ping(1)<<endl;
    cout<<obj->ping(100)<<endl;
    cout<<obj->ping(3001)<<endl;
    cout<<obj->ping(3002)<<endl;
    return 0;
}