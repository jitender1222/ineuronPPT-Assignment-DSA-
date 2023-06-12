#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *createNode(int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

Node *mergeLists(Node *a, Node *b)
{
    if (a == nullptr)
        return b;
    if (b == nullptr)
        return a;

    Node *result = nullptr;

    if (a->data <= b->data)
    {
        result = a;
        result->next = mergeLists(a->next, b);
    }
    else
    {
        result = b;
        result->next = mergeLists(a, b->next);
    }

    return result;
}

void displayList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *a = createNode(5);
    a->next = createNode(10);
    a->next->next = createNode(15);

    Node *b = createNode(2);
    b->next = createNode(3);
    b->next->next = createNode(20);

    cout << "Input: a: ";
    displayList(a);
    cout << "b: ";
    displayList(b);

    Node *merged = mergeLists(a, b);

    cout << "Output: ";
    displayList(merged);

    return 0;
}
