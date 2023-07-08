#include <iostream>
#include <unordered_map>
using namespace std;

bool isIsomorphic(string s, string t)
{
    if (s.length() != t.length())
        return false;

    unordered_map<char, char> sMap;
    unordered_map<char, char> tMap;

    for (int i = 0; i < s.length(); i++)
    {
        if (sMap.find(s[i]) != sMap.end() && sMap[s[i]] != t[i])
            return false;
        if (tMap.find(t[i]) != tMap.end() && tMap[t[i]] != s[i])
            return false;

        sMap[s[i]] = t[i];
        tMap[t[i]] = s[i];
    }

    return true;
}

int main()
{
    string s, t;
    cout << "Enter string s: ";
    cin >> s;
    cout << "Enter string t: ";
    cin >> t;

    bool isomorphic = isIsomorphic(s, t);

    cout << (isomorphic ? "true" : "false") << endl;

    return 0;
}
