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

Node *reverseKNodes(Node *head, int k)
{
    Node *current = head;
    Node *next = nullptr;
    Node *prev = nullptr;

    int count = 0;
    while (current != nullptr && count < k)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }

    if (next != nullptr)
        head->next = reverseKNodes(next, k);

    return prev;
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
    Node *head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(2);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    head->next->next->next->next->next = createNode(6);
    head->next->next->next->next->next->next = createNode(7);
    head->next->next->next->next->next->next->next = createNode(8);

    int k = 4;

    cout << "Input: LinkedList: ";
    displayList(head);
    cout << "K = " << k << endl;

    Node *newHead = reverseKNodes(head, k);

    cout << "Output: ";
    displayList(newHead);

    return 0;
}
