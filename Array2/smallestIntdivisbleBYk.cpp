#include<iostream>
#include<vector>
using namespace std;

int smallestRepunitDivByK(int k) {
    if (k % 2 == 0 || k % 5 == 0) return -1;
    int remainder = 0;
    for (int i = 1; i <= k; i++) {
        remainder = (remainder * 10 + 1) % k;
        if (remainder == 0) return i;
    }
    return -1;

}
int main() {
    int k = 1;
    cout << smallestRepunitDivByK(k) << endl;
    return 0;
}
