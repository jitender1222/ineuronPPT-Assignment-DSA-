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

void BinaryTreeToDLL(Node *root, Node **head)
{
    if (root == nullptr)
        return;

    static Node *prev = nullptr;

    BinaryTreeToDLL(root->left, head);

    if (*head == nullptr)
        *head = root;
    else
    {
        root->left = prev;
        prev->right = root;
    }
    prev = root;

    BinaryTreeToDLL(root->right, head);
}

void PrintDLL(Node *head)
{
    while (head != nullptr)
    {
        std::cout << head->data << " ";
        head = head->right;
    }
    std::cout << std::endl;
}

int main()
{
    Node *root = newNode(10);
    root->left = newNode(12);
    root->right = newNode(15);
    root->left->left = newNode(25);
    root->left->right = newNode(30);
    root->right->left = newNode(36);

    Node *head = nullptr;
    BinaryTreeToDLL(root, &head);

    std::cout << "Doubly Linked List: ";
    PrintDLL(head);

    return 0;
}
