#include <iostream>
#include <unordered_map>

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int data)
{
    Node *node = new Node();
    node->data = data;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

bool areTraversalsSame(int inOrder[], int preOrder[], int postOrder[], int n)
{
    std::unordered_map<int, int> inOrderMap;

    for (int i = 0; i < n; i++)
        inOrderMap[inOrder[i]] = i;

    int preIndex = 0, postIndex = n - 1;

    for (int i = 0; i < n; i++)
    {
        if (inOrderMap[preOrder[preIndex]] != inOrderMap[postOrder[postIndex]])
            return false;

        if (i + 1 < n)
        {
            int inOrderIndex = inOrderMap[preOrder[preIndex]];
            if (inOrderIndex > inOrderMap[preOrder[preIndex + 1]] &&
                inOrderIndex < inOrderMap[postOrder[postIndex - 1]])
                return false;
        }

        preIndex++;
        postIndex--;
    }

    return true;
}

int main()
{
    int inOrder[] = {4, 2, 5, 1, 3};
    int preOrder[] = {1, 2, 4, 5, 3};
    int postOrder[] = {4, 5, 2, 3, 1};
    int n = sizeof(inOrder) / sizeof(inOrder[0]);

    if (areTraversalsSame(inOrder, preOrder, postOrder, n))
        std::cout << "Yes" << std::endl;
    else
        std::cout << "No" << std::endl;

    return 0;
}
