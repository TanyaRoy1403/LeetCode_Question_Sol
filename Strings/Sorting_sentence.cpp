#include <iostream>
#include <string>
#include <sstream> // for stringstream

using namespace std;

int main() {
    string inputString = "This is a sample sentence";
    
    // Initialize a stringstream with the inputString
    stringstream ss(inputString);

    string word;
    int count = 0;

    // Read words from stringstream
    while (ss >> word) {
        count++;
    }

    cout << "Number of words: " << count << endl;

    return 0;
}
