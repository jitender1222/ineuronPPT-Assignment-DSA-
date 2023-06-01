/*

Question 4
You have a long flowerbed in which some of the plots are planted, and some are not.
However, flowers cannot be planted in adjacent plots.
Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.

Example 1:
Input: flowerbed = [1,0,0,0,1], n = 1
Output: true

*/

#include <iostream>
#include <vector>

using namespace std;

bool canPlaceFlowers(vector<int> &flowerbed, int n)
{
    int count = 0;
    int size = flowerbed.size();
    int i = 0;

    while (i < size)
    {
        if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == size - 1 || flowerbed[i + 1] == 0))
        {
            // Found an empty plot that satisfies the conditions
            flowerbed[i] = 1;
            count++;

            if (count >= n)
            {
                return true;
            }
        }

        i++;
    }

    return false;
}

int main()
{
    vector<int> flowerbed = {1, 0, 0, 0, 1};
    int n = 1;

    bool canPlant = canPlaceFlowers(flowerbed, n);
    cout << "Can plant " << n << " new flowers? " << (canPlant ? "true" : "false") << endl;

    return 0;
}
