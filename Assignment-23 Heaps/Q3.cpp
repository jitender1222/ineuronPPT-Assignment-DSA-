#include <iostream>
#include <queue>

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

void printRightView(Node *root)
{
    if (root == nullptr)
        return;

    std::queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();

        for (int i = 1; i <= n; i++)
        {
            Node *temp = q.front();
            q.pop();

            if (i == n)
                std::cout << temp->data << " ";

            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}

int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(4);
    root->left->right->right = newNode(5);
    root->left->right->right->right = newNode(6);

    std::cout << "Right View: ";
    printRightView(root);
    std::cout << std::endl;

    return 0;
}
