#include <iostream>
#include <unordered_map>
using namespace std;

bool isStrobogrammatic(string num)
{
    unordered_map<char, char> strobogrammaticMap = {
        {'0', '0'},
        {'1', '1'},
        {'6', '9'},
        {'8', '8'},
        {'9', '6'}};

    int left = 0, right = num.length() - 1;
    while (left <= right)
    {
        if (strobogrammaticMap.find(num[left]) == strobogrammaticMap.end() || strobogrammaticMap[num[left]] != num[right])
            return false;

        left++;
        right--;
    }

    return true;
}

int main()
{
    string num;
    cout << "Enter a number: ";
    cin >> num;

    bool isStrobogrammaticNumber = isStrobogrammatic(num);

    cout << (isStrobogrammaticNumber ? "true" : "false") << endl;

    return 0;
}
