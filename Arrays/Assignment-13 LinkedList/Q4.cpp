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

Node *reverseAlternateKNodes(Node *head, int k)
{
    Node *current = head;
    Node *next = nullptr;
    Node *prev = nullptr;

    int count = 0;
    while (current != nullptr && count < k)
    {
        next = current->next;
        if (count % 2 == 0)
        {
            current->next = prev;
            prev = current;
        }
        current = next;
        count++;
    }

    if (head != nullptr)
        head->next = current;

    count = 0;
    while (current != nullptr && count < k - 1)
    {
        current = current->next;
        count++;
    }

    if (current != nullptr)
        current->next = reverseAlternateKNodes(current->next, k);

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
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    head->next->next->next->next->next = createNode(6);
    head->next->next->next->next->next->next = createNode(7);
    head->next->next->next->next->next->next->next = createNode(8);
    head->next->next->next->next->next->next->next->next = createNode(9);

    int k = 3;

    cout << "Inputs: LinkedList: ";
    displayList(head);
    cout << "k = " << k << endl;

    Node *newHead = reverseAlternateKNodes(head, k);

    cout << "Output: ";
    displayList(newHead);

    return 0;
}
