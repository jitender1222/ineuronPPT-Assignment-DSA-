#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> findOriginalArray(vector<int>& changed) {
    if (changed.size() % 2 != 0) {
        return {};
    }
    
    unordered_map<int, int> count;
    vector<int> original;
    
    for (int num : changed) {
        count[num]++;
    }
    
    for (int num : changed) {
        if (count[num] == 0) {
            continue;
        }
        
        if (count[num * 2] == 0) {
            return {};
        }
        
        original.push_back(num);
        count[num]--;
        count[num * 2]--;
    }
    
    return original;
}

int main() {
    vector<int> changed = {1, 3, 4, 2, 6, 8};
    
    vector<int> result = findOriginalArray(changed);
    
    for (int num : result) {
        cout << num << " ";
    }
    
    return 0;
}
