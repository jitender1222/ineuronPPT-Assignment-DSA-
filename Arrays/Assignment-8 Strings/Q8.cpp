#include <iostream>
#include <unordered_set>

using namespace std;

bool buddyStrings(string s, string goal)
{
    int n = s.length();
    int m = goal.length();

    if (n != m || n < 2 || m < 2)
        return false;

    if (s == goal)
    {
        unordered_set<char> uniqueChars;

        for (char c : s)
        {
            if (uniqueChars.find(c) != uniqueChars.end())
                return true;

            uniqueChars.insert(c);
        }

        return false;
    }

    int first = -1, second = -1;

    for (int i = 0; i < n; i++)
    {
        if (s[i] != goal[i])
        {
            if (first == -1)
                first = i;
            else if (second == -1)
                second = i;
            else
                return false;
        }
    }

    return (second != -1 && s[first] == goal[second] && s[second] == goal[first]);
}

int main()
{
    string s = "ab";
    string goal = "ba";
    bool result = buddyStrings(s, goal);
    cout << "Can Swap: " << (result ? "true" : "false") << endl;

    return 0;
}
