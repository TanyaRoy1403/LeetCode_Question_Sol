#include<iostream>
#include<vector> 
#include<unordered_map>
using namespace std;

class Graph{
    public:
        unordered_map<int, vector<int>>adjList;
    
    void addEdges(int u ,int v ,bool direction){
        //direction=0->undirected
        //direction=1->directed
        if(direction==0){
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }else{
            adjList[u].push_back(v);
        }
    }

};
// void printList(unordered_map<int, vector<int>>list){
//     for (auto pair : list) {
//         cout << pair.first << " -> ";
//         for (auto neighbor : pair.second) {
//             cout << neighbor << " ";
//         }
//         cout << endl;
//     }
// }
void printList(unordered_map<int, vector<int>> list) {
    unordered_map<int, bool> printed;

    // First print all nodes that appear as keys
    for (auto pair : list) {
        cout << pair.first << " -> ";
        for (auto neighbor : pair.second) {
            cout << neighbor << " ";
        }
        cout << endl;
        printed[pair.first] = true;
    }

    // Then print nodes that only appeared as neighbors (not as keys)
    for (auto pair : list) {
        for (int neighbor : pair.second) {
            if (!printed[neighbor]) {
                cout << neighbor << " -> " << endl;
                printed[neighbor] = true;
            }
        }
    }
}

int main(){
    Graph g;
    g.addEdges(0,1,1);
    g.addEdges(0,2,1);
    g.addEdges(1,2,1);
    g.addEdges(2,3,1);
    printList(g.adjList);
}