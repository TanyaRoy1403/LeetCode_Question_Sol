#include<iostream>
#include<vector>
using namespace std;

bool divisorGame(int n) {
    return n % 2 == 0;
}
int main() {
    int n = 2;
    cout << divisorGame(n) << endl;
    return 0;
}