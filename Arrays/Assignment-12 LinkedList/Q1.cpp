#include <iostream>

struct Node
{
    int data;
    Node *next;
};

Node *deleteMiddle(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return nullptr;

    Node *slowPtr = head;
    Node *fastPtr = head;
    Node *prev = nullptr;

    while (fastPtr != nullptr && fastPtr->next != nullptr)
    {
        fastPtr = fastPtr->next->next;
        prev = slowPtr;
        slowPtr = slowPtr->next;
    }

    prev->next = slowPtr->next;
    delete slowPtr;
    return head;
}

void printList(Node *head)
{
    while (head != nullptr)
    {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main()
{
    Node *head = new Node{1, nullptr};
    head->next = new Node{2, nullptr};
    head->next->next = new Node{3, nullptr};
    head->next->next->next = new Node{4, nullptr};
    head->next->next->next->next = new Node{5, nullptr};

    std::cout << "Original Linked List: ";
    printList(head);

    head = deleteMiddle(head);

    std::cout << "Modified Linked List: ";
    printList(head);

    return 0;
}
