#include <iostream>
#include <vector>

using namespace std;

int compress(vector<char> &chars)
{
    int n = chars.size();
    int index = 0;
    int count = 1;

    for (int i = 1; i <= n; i++)
    {
        if (i < n && chars[i] == chars[i - 1])
            count++;
        else
        {
            chars[index++] = chars[i - 1];

            if (count > 1)
            {
                string countStr = to_string(count);

                for (char c : countStr)
                    chars[index++] = c;
            }

            count = 1;
        }
    }

    return index;
}

int main()
{
    vector<char> chars = {'a', 'a', 'b', 'b', 'c', 'c', 'c'};
    int result = compress(chars);

    cout << "Compressed Length: " << result << endl;
    cout << "Compressed String: ";

    for (int i = 0; i < result; i++)
        cout << chars[i] << " ";

    cout << endl;
    return 0;
}
