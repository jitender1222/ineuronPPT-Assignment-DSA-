#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<vector<int>> findMissingNumbers(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> set1(nums1.begin(), nums1.end());
    unordered_set<int> set2(nums2.begin(), nums2.end());
    
    vector<int> missingNums1;
    vector<int> missingNums2;
    
    for (int num : nums1) {
        if (set2.find(num) == set2.end()) {
            missingNums1.push_back(num);
        }
    }
    
    for (int num : nums2) {
        if (set1.find(num) == set1.end()) {
            missingNums2.push_back(num);
        }
    }
    
    return {missingNums1, missingNums2};
}

int main() {
    vector<int> nums1 = {1, 2, 3};
    vector<int> nums2 = {2, 4, 6};
    
    vector<vector<int>> result = findMissingNumbers(nums1, nums2);
    
    for (int num : result[0]) {
        cout << num << " ";
    }
    cout << endl;
    
    for (int num : result[1]) {
        cout << num << " ";
    }
    
    return 0;
}
