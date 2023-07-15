#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> findDuplicates(vector<int>& nums) {
    vector<int> result;
    
    for (int num : nums) {
        int index = abs(num) - 1;
        
        if (nums[index] < 0) {
            result.push_back(abs(num));
        } else {
            nums[index] = -nums[index];
        }
    }
    
    return result;
}

int main() {
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    
    vector<int> result = findDuplicates(nums);
    
    for (int num : result) {
        cout << num << " ";
    }
    
    return 0;
}
