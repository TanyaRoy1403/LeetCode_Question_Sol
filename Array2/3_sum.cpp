#include <vector>
#include <algorithm>
#include <set>
#include <iostream>
using namespace std;

/*Given an integer array arr, return all the triplets [arr[i], arr[j], arr[k]] such that i != j, i != k, and j != k, and arr[i] + arr[j] + arr[k] == 0.
Notice that the solution set must not contain duplicate triplets.*/

//brute force
bool binarySearch(const vector<int>& nums, int start, int end, int target) {
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (nums[mid] == target) {
            return true;
        } else if (nums[mid] < target) {
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return false;
}

vector<vector<int>> threeSum(vector<int>& nums) {
    set<vector<int>> s; // to get unique triplets
    sort(nums.begin(), nums.end());   //O(logn)
    int n = nums.size();
    vector<int> temp(3);
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int target = -nums[i] - nums[j];
            if (binarySearch(nums, j + 1, n - 1, target)) {
                temp[0] = nums[i];
                temp[1] = nums[j];
                temp[2] = target;
                sort(temp.begin(), temp.end());
                // to get triplet in an order, will be easy to check if 
                // duplicate exists or not
                s.insert(temp);
            }
        }
    }

    vector<vector<int>> ans;
    for (const auto& triplet : s) {
        ans.push_back(triplet);
    }

    return ans;
}
// t.c-->O(N*N*log(N))
// s.c-->O(N)

//optimal solution 
//two pointer and two_sum concept(sorted)
void two_sum(vector<int>&arr,int k,vector<vector<int>>&ans,int target){
    int n=arr.size();
    int i=k;
    int j=arr.size()-1;
    while(i<j){  //O(N)
        int sum=arr[i]+arr[j];
        if(target>sum){
            i++;
        }else if(target<sum){
            j--;
        }else{
            ans.push_back({-target,arr[i],arr[j]});  //target mil gya h
            while(i<n&& arr[i]==arr[i+1]){  //O(N)
                i++;  //to remove duplicates
            }
            while(j>=0&&arr[j]==arr[j-1]){    //to check ki jo element ko fix kiye the(n1,arr[i-1])  yehi same ele khi agla fix hone wala ele to nhi h
                j--; //to remove dupliactes
            }
            i++; //target mil jane pe
            j--; //target mil jane pe
        }

    }
    /*-------------Time Complexity: O(n)
Space Complexity: O(n)--------------------------*/
}

vector<vector<int>> three_sum(vector<int>&arr){

    if(arr.size()<3){
        return {};
    }
    vector<vector<int>>ans;
    sort(arr.begin(),arr.end());
    for(int i=0;i<arr.size()-2;i++){  //kyu ki ek element hmne fix kr diya tha or arr ka size n-1 hota hi to final size n-2
            if(i!=0&& arr[i]==arr[i-1]){                  //i!=0 kyu phela ele to fix hi h na
             continue;
            }
        two_sum(arr,i+1,ans,-arr[i]);
    }
    return ans;
    /*------------Time Complexity: O(n^2)
Space Complexity: O(n) for in-place operations + space for storing results in ans.---------------*/
}
int main() {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> result = three_sum(nums);
    
    for (const auto& triplet : result) {
        for (int num : triplet) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}
