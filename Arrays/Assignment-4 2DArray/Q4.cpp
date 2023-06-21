#include <iostream>
#include <stack>

struct Node
{
    char data;
    Node *next;
};

bool isPalindrome(Node *head)
{
    std::stack<char> charStack;
    Node *slowPtr = head;
    Node *fastPtr = head;

    // Push characters of the first half into the stack
    while (fastPtr != nullptr && fastPtr->next != nullptr)
    {
        charStack.push(slowPtr->data);
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }

    // Skip the middle element for odd-length linked list
    if (fastPtr != nullptr)
        slowPtr = slowPtr->next;

    // Compare the remaining half with the stack elements
    while (slowPtr != nullptr)
    {
        if (slowPtr->data != charStack.top())
            return false;
        charStack.pop();
        slowPtr = slowPtr->next;
    }

    return true;
}

int main()
{
    Node *head = new Node{'R', nullptr};
    head->next = new Node{'A', nullptr};
    head->next->next = new Node{'D', nullptr};
    head->next->next->next = new Node{'A', nullptr};
    head->next->next->next->next = new Node{'R', nullptr};

    if (isPalindrome(head))
        std::cout << "Yes, it is a Palindrome!" << std::endl;
    else
        std::cout << "No, it is not a Palindrome!" << std::endl;

    return 0;
}
