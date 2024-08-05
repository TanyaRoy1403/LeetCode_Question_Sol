#include<iostream>
using namespace std;
// Creation of 2d array in heap
 
int main() {
   
    int** arr = new int*[4]; //double pointer jo array of pointers ko point kr rha h
    // har ek pointer (array of pointers me se) ke liye ek 1d array create
    for (int i = 0; i < 4; i++) {  //row size=4
        arr[i] = new int[4]; //col size=4
    }

    // Input 
    cout << "Enter the elements of the 2D array (4x4):" << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> arr[i][j];
        }
    }

    // Print
    cout << "The elements of the 2D array are:" << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;  // Print newline after each row
    }

    // Deallocate memory
    for (int i = 0; i < 4; i++) {
        delete[] arr[i]; //deleting array
    }
    delete[] arr;

    return 0;
}
