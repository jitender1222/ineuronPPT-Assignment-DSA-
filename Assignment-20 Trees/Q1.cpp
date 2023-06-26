#include <iostream>
#include <climits>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *createNode(int data)
{
    Node *newNode = new Node();
    if (!newNode)
    {
        cout << "Memory error!\n";
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int findMaxSubtreeSumUtil(Node *root, int &maxSum)
{
    if (root == NULL)
        return 0;

    int currentSum = root->data + findMaxSubtreeSumUtil(root->left, maxSum) + findMaxSubtreeSumUtil(root->right, maxSum);

    maxSum = max(maxSum, currentSum);

    return currentSum;
}

int findMaxSubtreeSum(Node *root)
{
    if (root == NULL)
        return 0;

    int maxSum = INT_MIN;
    findMaxSubtreeSumUtil(root, maxSum);

    return maxSum;
}

int main()
{
    Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    int maxSum = findMaxSubtreeSum(root);
    cout << "Maximum subtree sum: " << maxSum << endl;

    return 0;
}
