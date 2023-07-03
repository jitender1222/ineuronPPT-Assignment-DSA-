#include <iostream>

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

Node *flipBinaryTree(Node *root)
{
    if (root == nullptr || (root->left == nullptr && root->right == nullptr))
        return root;

    Node *flippedRoot = flipBinaryTree(root->left);

    root->left->left = root->right;
    root->left->right = root;
    root->left = nullptr;
    root->right = nullptr;

    return flippedRoot;
}

void inorderTraversal(Node *root)
{
    if (root == nullptr)
        return;

    inorderTraversal(root->left);
    std::cout << root->data << " ";
    inorderTraversal(root->right);
}

int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    std::cout << "Before flipping: ";
    inorderTraversal(root);
    std::cout << std::endl;

    Node *flippedRoot = flipBinaryTree(root);

    std::cout << "After flipping: ";
    inorderTraversal(flippedRoot);
    std::cout << std::endl;

    return 0;
}
