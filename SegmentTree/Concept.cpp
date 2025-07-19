#include<iostream>
#include<vector>
using namespace std;
// class Node{
//     public:
//     int data;
//     int next;
//     Node(int val){
//         this->data=val;
//         next=NULL;
//     }
// };
vector<int> tree;
void BuildTree(int l, int r, int i, vector<int>& arr) {
    if (l == r) {
        tree[i] = arr[l];
        return;
    }
    int mid = (l + r) / 2;
    BuildTree(l, mid, 2*i + 1, arr);
    BuildTree(mid + 1, r, 2*i + 2, arr);
    tree[i] = tree[2*i + 1] + tree[2*i + 2];
}
int main(){
   vector<int> arr = {1, 3, 5, 7};
    int n = arr.size();
    tree.resize(4 * n);  // Safe size for segment tree

    BuildTree(0, n - 1, 0, arr);

    // Print tree array
    cout << "Segment Tree:";
    for (int i = 0; i < 2 * n; i++) {
        cout << tree[i] << " ";
    }
    cout << endl;
    return 0;
}
