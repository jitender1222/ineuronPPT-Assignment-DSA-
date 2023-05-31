/*
<aside>
💡 **Q4.** You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.

**Example 1:**
Input: digits = [1,2,3]
Output: [1,2,4]

**Explanation:** The array represents the integer 123.

Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].

</aside>
*/

// Solution

#include <iostream>

using namespace std;

int *increment_integer(int *digits, int n)
{
    int carry = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        int sum = digits[i] + carry;
        digits[i] = sum % 10;
        carry = sum / 10;
    }

    if (carry > 0)
    {
        int *new_digits = new int[n + 1];
        new_digits[0] = carry;
        for (int i = 1; i <= n; i++)
        {
            new_digits[i] = digits[i - 1];
        }

        return new_digits;
    }
    else
    {
        return digits;
    }
}

int main()
{
    int digits[] = {1, 2, 3};
    int n = sizeof(digits) / sizeof(digits[0]);

    int *new_digits = increment_integer(digits, n);

    for (int i = 0; i < n; i++)
    {
        cout << new_digits[i] << " ";
    }

    cout << endl;

    return 0;
}
