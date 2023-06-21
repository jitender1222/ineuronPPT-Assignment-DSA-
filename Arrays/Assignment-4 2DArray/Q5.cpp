#include <iostream>
#include <unordered_set>

struct Node
{
    int data;
    Node *next;
};

void removeLoop(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return;

    Node *slowPtr = head;
    Node *fastPtr = head;
    Node *prev = nullptr;

    while (fastPtr != nullptr && fastPtr->next != nullptr)
    {
        fastPtr = fastPtr->next->next;
        prev = slowPtr;
        slowPtr = slowPtr->next;

        if (slowPtr == fastPtr)
            break;
    }

    // No loop found
    if (slowPtr != fastPtr)
        return;

    // Move slowPtr to head and advance both pointers by one step until they meet at the loop start
    slowPtr = head;
    while (slowPtr->next != fastPtr->next)
    {
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next;
    }

    // Break the loop
    fastPtr->next = nullptr;
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

    // Create a loop for testing
    head->next->next->next->next->next = head->next->next;

    std::cout << "Before Removing Loop: ";
    printList(head);

    removeLoop(head);

    std::cout << "After Removing Loop: ";
    printList(head);

    return 0;
}
