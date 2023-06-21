#include <iostream>

struct Node
{
    int data;
    Node *next;
};

void alternateInsert(Node **first, Node **second)
{
    if (*first == nullptr || *second == nullptr)
        return;

    Node *firstCurr = *first;
    Node *secondCurr = *second;
    Node *firstNext;
    Node *secondNext;

    while (firstCurr != nullptr && secondCurr != nullptr)
    {
        // Store the next pointers
        firstNext = firstCurr->next;
        secondNext = secondCurr->next;

        // Make secondCurr as the next of firstCurr
        secondCurr->next = firstNext;
        firstCurr->next = secondCurr;

        // Move pointers to the next positions
        firstCurr = firstNext;
        secondCurr = secondNext;
    }

    // Update the head of the second list
    *second = secondCurr;
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
    Node *first = new Node{1, nullptr};
    first->next = new Node{3, nullptr};
    first->next->next = new Node{5, nullptr};

    Node *second = new Node{2, nullptr};
    second->next = new Node{4, nullptr};
    second->next->next = new Node{6, nullptr};

    std::cout << "First List: ";
    printList(first);
    std::cout << "Second List: ";
    printList(second);

    alternateInsert(&first, &second);

    std::cout << "Modified First List: ";
    printList(first);
    std::cout << "Modified Second List: ";
    printList(second);

    return 0;
}
