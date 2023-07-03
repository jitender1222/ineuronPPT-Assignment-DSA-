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

void printLeftView(Node *root)
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

            if (i == 1)
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
    Node *root = newNode(4);
    root->left = newNode(5);
    root->right = newNode(2);
    root->right->left = newNode(3);
    root->right->right = newNode(1);
    root->right->left->left = newNode(6);
    root->right->left->right = newNode(7);

    std::cout << "Left View: ";
    printLeftView(root);
    std::cout << std::endl;

    return 0;
}
