#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
using namespace std;

int countingSortCalls = 0;
const int THRESHOLD = 16;

// Counting Sort (for subarrays of size <= 16)
void countingSort(vector<int>& arr, int l, int r) {
    countingSortCalls++;

    int minVal = INT_MAX, maxVal = INT_MIN;
    for (int i = l; i <= r; ++i) {
        minVal = min(minVal, arr[i]);
        maxVal = max(maxVal, arr[i]);
    }

    int range = maxVal - minVal + 1;
    vector<int> count(range, 0);

    for (int i = l; i <= r; ++i) {
        count[arr[i] - minVal]++;
    }

    int index = l;
    for (int i = 0; i < range; ++i) {
        while (count[i]--) {
            arr[index++] = i + minVal;
        }
    }
}

// Hybrid Sort (QuickSort + Counting Sort)
void hybridSort(vector<int>& arr, int l, int r) {
    if (l >= r)
        return;

    int size = r - l + 1;
    if (size <= THRESHOLD) {
        countingSort(arr, l, r);
        return;
    }

    // QuickSort logic with last element as pivot
    int pivot = arr[r];
    int i = l - 1;

    for (int j = l; j < r; ++j) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    i++;
    swap(arr[i], arr[r]);

    hybridSort(arr, l, i - 1);
    hybridSort(arr, i + 1, r);
}

int main() {
    vector<int> arr={59 ,89 ,15 ,185 ,4181 ,18 ,154 ,15 ,1848 ,1884 ,8 ,481 ,8181 ,84};
  

    hybridSort(arr, 0, arr.size() - 1);
    cout<<"here is ans";
    cout << countingSortCalls << endl;
    return 0;
}
