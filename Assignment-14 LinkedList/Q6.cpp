#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

int getLength(ListNode *head)
{
    int length = 0;
    ListNode *temp = head;
    while (temp != nullptr)
    {
        length++;
        temp = temp->next;
    }
    return length;
}

ListNode *leftShiftLinkedList(ListNode *head, int k)
{
    if (head == nullptr || head->next == nullptr || k == 0)
        return head;

    int length = getLength(head);
    k = k % length;

    if (k == 0)
        return head;

    ListNode *fast = head;
    ListNode *slow = head;
    ListNode *newHead = nullptr;

    while (k > 0)
    {
        fast = fast->next;
        k--;
    }

    while (fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next;
    }

    newHead = slow->next;
    slow->next = nullptr;
    fast->next = head;

    return newHead;
}

void printLinkedList(ListNode *head)
{
    ListNode *temp = head;
    while (temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
}

int main()
{
    // Create a linked list

    ListNode *head = new ListNode(2);
    ListNode *node2 = new ListNode(4);
    ListNode *node3 = new ListNode(7);
    ListNode *node4 = new ListNode(8);
    ListNode *node5 = new ListNode(9);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    // Left shift the linked list by k = 3
    head = leftShiftLinkedList(head, 3);

    // Print the shifted linked list
    printLinkedList(head);

    return 0;
}
