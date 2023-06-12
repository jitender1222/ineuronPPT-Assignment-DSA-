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

void removeDuplicates(Node *head)
{
    Node *current = head;
    Node *nextNode;

    if (current == nullptr)
        return;

    while (current->next != nullptr)
    {
        if (current->data == current->next->data)
        {
            nextNode = current->next->next;
            delete current->next;
            current->next = nextNode;
        }
        else
        {
            current = current->next;
        }
    }
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
    Node *head = createNode(11);
    head->next = createNode(11);
    head->next->next = createNode(11);
    head->next->next->next = createNode(21);
    head->next->next->next->next = createNode(43);
    head->next->next->next->next->next = createNode(43);
    head->next->next->next->next->next->next = createNode(60);

    cout << "Input: LinkedList: ";
    displayList(head);

    removeDuplicates(head);

    cout << "Output: ";
    displayList(head);

    return 0;
}
