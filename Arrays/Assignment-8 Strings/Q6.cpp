#include <iostream>
#include <vector>

using namespace std;

vector<int> findAnagrams(string s, string p)
{
    vector<int> pCount(26, 0);
    vector<int> sCount(26, 0);
    vector<int> result;

    if (s.length() < p.length())
        return result;

    for (char c : p)
        pCount[c - 'a']++;

    for (int i = 0; i < p.length(); i++)
        sCount[s[i] - 'a']++;

    if (pCount == sCount)
        result.push_back(0);

    for (int i = p.length(); i < s.length(); i++)
    {
        sCount[s[i - p.length()] - 'a']--;
        sCount[s[i] - 'a']++;

        if (pCount == sCount)
            result.push_back(i - p.length() + 1);
    }

    return result;
}

int main()
{
    string s = "cbaebabacd";
    string p = "abc";
    vector<int> result = findAnagrams(s, p);

    cout << "Anagram Start Indices: ";
    for (int idx : result)
        cout << idx << " ";

    cout << endl;

    return 0;
}
