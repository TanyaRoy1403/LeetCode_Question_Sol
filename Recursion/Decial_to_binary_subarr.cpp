#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

// Function to convert decimal to binary using specified set {128, 64, 32, 16, 8, 4, 2, 1}
void decimalToBinary(int decimal) {
    int placeValues[] = {128, 64, 32, 16, 8, 4, 2, 1};
    int n = sizeof(placeValues) / sizeof(placeValues[0]);

    vector<int> binaryResult(n, 0);

    for (int i = 0; i < n; ++i) {
        if (decimal >= placeValues[i]) {
            binaryResult[i] = 1;
            decimal -= placeValues[i];
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << binaryResult[i];
    }
    cout << endl;
}

vector<int> d_to_b(int n){

    vector<int>ans;
    while(n>0){
        int sum=n%2;
        ans.push_back(sum);
        n/=2;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main() {
//    int decimal;
//    cout << "Enter a decimal number: ";
//        cin >> decimal;
//    decimalToBinary(decimal);
int n=10;
   vector<int>ans=d_to_b(n);
   for(auto &ch:ans){
    cout<<ch;
   }


    return 0;
}
