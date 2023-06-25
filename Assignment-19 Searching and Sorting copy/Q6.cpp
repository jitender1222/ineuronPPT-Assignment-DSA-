#include <iostream>
#include <vector>

using namespace std;

vector<int> mergeArrays(vector<int> &arr1, vector<int> &arr2)
{
    int n1 = arr1.size();
    int n2 = arr2.size();

    vector<int> merged;
    int i = 0, j = 0;

    while (i < n1 && j < n2)
    {
        if (arr1[i] <= arr2[j])
        {
            merged.push_back(arr1[i]);
            i++;
        }
        else
        {
            merged.push_back(arr2[j]);
            j++;
        }
    }

    while (i < n1)
    {
        merged.push_back(arr1[i]);
        i++;
    }

    while (j < n2)
    {
        merged.push_back(arr2[j]);
        j++;
    }

    return merged;
}

int main()
{
    // Create the input arrays
    vector<int> arr1;
    vector<int> arr2;
    // Add code to populate the arrays...

    // Merge the arrays
    vector<int> mergedArray = mergeArrays(arr1, arr2);

    // Print the merged array
    for (int num : mergedArray)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
