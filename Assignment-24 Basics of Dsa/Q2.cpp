#include <iostream>
#include <unordered_set>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    int n = s.length();
    int maxLength = 0;
    int i = 0, j = 0;

    unordered_set<char> uniqueChars;

    while (j < n)
    {
        if (uniqueChars.find(s[j]) == uniqueChars.end())
        {
            uniqueChars.insert(s[j]);
            maxLength = max(maxLength, j - i + 1);
            j++;
        }
        else
        {
            uniqueChars.erase(s[i]);
            i++;
        }
    }

    return maxLength;
}

int main()
{
    string s = "abcabcbb";
    int length = lengthOfLongestSubstring(s);
    cout << length << endl;
    return 0;
}
