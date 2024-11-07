#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

/*Design a class to find the kth largest element in a stream. Note that it is the kth largest element in the sorted order, 
not the kth distinct element.

Implement KthLargest class:

KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of integers nums.
int add(int val) Appends the integer val to the stream and returns the element representing the kth largest element in the stream.*/

/*//^-------------------------------Brute Force-->Binary search,sorting----------------------------------------------------------*/

class KthLargest {
public:
    vector<int> numbers;
    int K;
    KthLargest(int k, vector<int>& nums) {
        K = k;
        numbers = nums;
        sort(numbers.begin(), numbers.end());
    }
    
    int add(int val) {
        numbers.insert(numbers.begin() + getPos(val), val);
        return numbers[numbers.size() - K];
    }

    int getPos(int val) {
        int l = 0;
        int r = numbers.size() - 1;
        int mid;
        while(l <= r) {
            mid = (l + r) / 2;
            if(numbers[mid] == val) return mid;
            if(numbers[mid] > val) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        return l;
    }
};

/*//^----------------------------------------optimal solution -->heap-------------------------------------------*/
class KthLargest {
public:
    int kth;
    priority_queue<int, vector<int>, greater<int>> Q;
    KthLargest(int k, vector<int>& nums) {
        this->kth = k;
        for (auto& ch : nums) {
            Q.push(ch);
            if (Q.size() > k) {
                Q.pop();
            }
        }
    }

    int add(int val) {
        Q.push(val);
        if (Q.size() > kth) {
            Q.pop();
        }
        return Q.top();
    }
};