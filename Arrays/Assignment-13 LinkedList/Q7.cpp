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

Node *reverseDoublyLinkedList(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    Node *current = head;
    Node *temp = nullptr;

    while (current != nullptr)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != nullptr)
        head = temp->prev;

    return head;
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
    Node *head = createNode(10);
    head->next = createNode(8);
    head->next->prev = head;
    head->next->next = createNode(4);
    head->next->next->prev = head->next;
    head->next->next->next = createNode(2);
    head->next->next->next->prev = head->next->next;

    cout << "Original Linked list: ";
    displayList(head);

    Node *reversed = reverseDoublyLinkedList(head);

    cout << "Reversed Linked list: ";
    displayList(reversed);

    return 0;
}
