#include <iostream>
using namespace std;

string addStrings(string num1, string num2)
{
    int carry = 0;
    int i = num1.length() - 1, j = num2.length() - 1;
    string result = "";

    while (i >= 0 || j >= 0 || carry > 0)
    {
        int sum = carry;

        if (i >= 0)
            sum += num1[i] - '0';
        if (j >= 0)
            sum += num2[j] - '0';

        carry = sum / 10;
        sum = sum % 10;
        result = to_string(sum) + result;

        i--;
        j--;
    }

    return result;
}

int main()
{
    string num1, num2;
    cout << "Enter num1: ";
    cin >> num1;
    cout << "Enter num2: ";
    cin >> num2;

    string sum = addStrings(num1, num2);

    cout << "Sum: " << sum << endl;

    return 0;
}
