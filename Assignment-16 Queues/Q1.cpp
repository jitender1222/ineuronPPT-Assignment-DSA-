#include <iostream>
#include <unordered_map>

int firstUniqChar(std::string s)
{
    std::unordered_map<char, int> frequency;

    // Count the frequency of each character in the string
    for (char c : s)
    {
        frequency[c]++;
    }

    // Find the first non-repeating character
    for (int i = 0; i < s.length(); i++)
    {
        if (frequency[s[i]] == 1)
        {
            return i;
        }
    }

    return -1; // No non-repeating character found
}

int main()
{
    std::string s = "leetcode";
    std::cout << firstUniqChar(s) << std::endl; // Output: 0

    s = "loveleetcode";
    std::cout << firstUniqChar(s) << std::endl; // Output: 2

    s = "aabb";
    std::cout << firstUniqChar(s) << std::endl; // Output: -1

    return 0;
}
