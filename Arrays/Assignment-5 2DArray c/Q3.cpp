#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
    vector<int> result;
    
    for (int num : nums) {
        result.push_back(num * num);
    }
    
    sort(result.begin(), result.end());
    
    return result;
}

int main() {
    vector<int> nums = {-4, -1, 0, 3, 10};
    
    vector<int> result = sortedSquares(nums);
    
    for (int num : result) {
        cout << num << " ";
    }
    
    return 0;
}
