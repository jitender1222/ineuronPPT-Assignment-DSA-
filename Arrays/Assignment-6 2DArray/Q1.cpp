#include <iostream>
#include <vector>

using namespace std;

vector<int> reconstructPermutation(string s)
{
    int n = s.size();
    vector<int> perm(n + 1);

    int minNum = 0;
    int maxNum = n;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'I')
        {
            perm[i] = minNum;
            minNum++;
        }
        else
        {
            perm[i] = maxNum;
            maxNum--;
        }
    }

    perm[n] = minNum;

    return perm;
}

int main()
{
    string s = "IDID";

    vector<int> result = reconstructPermutation(s);

    for (int num : result)
    {
        cout << num << " ";
    }

    return 0;
}
