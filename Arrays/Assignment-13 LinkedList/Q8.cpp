#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
};

Node *createNode(int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

void deleteNodeAtPosition(Node **head, int position)
{
    if (*head == nullptr)
        return;

    Node *current = *head;

    if (position == 0)
    {
        *head = current->next;
        if (*head != nullptr)
            (*head)->prev = nullptr;
        delete current;
        return;
    }

    int count = 0;
    while (current != nullptr && count < position)
    {
        current = current->next;
        count++;
    }

    if (current == nullptr)
        return;

    current->prev->next = current->next;
    if (current->next != nullptr)
        current->next->prev = current->prev;
    delete current;
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
    head->next->prev = head;
    head->next->next = createNode(3);
    head->next->next->prev = head->next;
    head->next->next->next = createNode(4);
    head->next->next->next->prev = head->next->next;

    int position = 2;

    cout << "Original Linked list: ";
    displayList(head);

    deleteNodeAtPosition(&head, position);

    cout << "Linked list after deletion: ";
    displayList(head);

    return 0;
}
