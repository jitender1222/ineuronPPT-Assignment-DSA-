#include <iostream>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode *insert(TreeNode *root, int key)
{
    if (root == nullptr)
        return new TreeNode(key);

    if (key < root->val)
        root->left = insert(root->left, key);
    else if (key > root->val)
        root->right = insert(root->right, key);

    return root;
}

TreeNode *lca(TreeNode *root, int n1, int n2)
{
    if (root == nullptr)
        return nullptr;

    if (root->val > n1 && root->val > n2)
        return lca(root->left, n1, n2);

    if (root->val < n1 && root->val < n2)
        return lca(root->right, n1, n2);

    return root;
}

int findDistance(TreeNode *root, int key)
{
    if (root == nullptr)
        return -1;

    if (root->val == key)
        return 0;

    if (key < root->val)
        return 1 + findDistance(root->left, key);

    return 1 + findDistance(root->right, key);
}

int findDistanceBetweenNodes(TreeNode *root, int node1, int node2)
{
    TreeNode *lowestCommonAncestor = lca(root, node1, node2);

    int dist1 = findDistance(lowestCommonAncestor, node1);
    int dist2 = findDistance(lowestCommonAncestor, node2);

    return dist1 + dist2;
}

int main()
{
    TreeNode *root = nullptr;
    int n = 9;
    int values[] = {8, 3, 1, 6, 4, 7, 10, 14, 13};
    int node1 = 6;
    int node2 = 14;

    for (int i = 0; i < n; i++)
        root = insert(root, values[i]);

    int distance = findDistanceBetweenNodes(root, node1, node2);

    std::cout << "The distance between the two keys = " << distance << std::endl;

    return 0;
}
