#include <iostream>
#include <queue>

using namespace std;

bool checkLevelOrderBST(int arr[], int size)
{
    if (size == 0)
        return true;

    queue<int> q;
    int i = 1;

    q.push(arr[0]);

    while (i < size)
    {
        int current = q.front();
        q.pop();

        if (i < size && arr[i] < current)
            q.push(arr[i++]);

        if (i < size && arr[i] > current)
        {
            while (!q.empty())
            {
                if (arr[i] < q.front())
                    return false;
                q.pop();
            }
            q.push(arr[i++]);
        }
    }

    return true;
}

int main()
{
    int arr1[] = {7, 4, 12, 3, 6, 8, 1, 5, 10};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);

    bool isLevelOrderBST1 = checkLevelOrderBST(arr1, size1);
    cout << "Is arr1 a level order traversal of a BST? " << (isLevelOrderBST1 ? "Yes" : "No") << endl;

    int arr2[] = {11, 6, 13, 5, 12, 10};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    bool isLevelOrderBST2 = checkLevelOrderBST(arr2, size2);
    cout << "Is arr2 a level order traversal of a BST? " << (isLevelOrderBST2 ? "Yes" : "No") << endl;

    return 0;
}
