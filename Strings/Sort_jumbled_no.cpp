#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

/*You are given a 0-indexed integer array mapping which represents the mapping rule of a shuffled decimal system. mapping[i] = j 
means digit i should be mapped to digit j in this system.

The mapped value of an integer is the new integer obtained by replacing each occurrence of digit i in the integer with mapping[i] for all 0 <= i <= 9.

You are also given another integer array nums. Return the array nums sorted in non-decreasing order based on the mapped values of its elements.

Notes:

Elements with the same mapped values should appear in the same relative order as in the input.
The elements of nums should only be sorted based on their mapped values and not be replaced by them.*/


int getMappedNum(int num, vector<int>& mapping) {
        if(num < 10) {
            return mapping[num];
        }

        int mappedNum  = 0;
        int plaveValue = 1;

        while(num) {
            int lastDigit   = num%10;
            int mappedDigit = mapping[lastDigit];
            mappedNum      += plaveValue * mappedDigit;

            plaveValue *= 10;
            num       /= 10;
        }

        return mappedNum;

    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> vec;

        for(int i = 0; i < n; i++) {
            int mappedNum = getMappedNum(nums[i], mapping);

            vec.push_back({mappedNum, i});
        }

        sort(begin(vec), end(vec));
        vector<int> result;

        for(auto &p : vec) {
            int originalNumIdx = p.second;
            result.push_back(nums[originalNumIdx]);
        }
        return result;
}
int main(){
    vector<int>mapping={8,9,4,0,2,1,3,5,7,6};
    vector<int>nums={991,338,38};
    vector<int>ans=sortJumbled(mapping,nums);
}
