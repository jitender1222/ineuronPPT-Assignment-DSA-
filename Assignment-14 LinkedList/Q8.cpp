#include <iostream>
#include <unordered_map>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *removeZeroSumSublists(ListNode *head)
{
    if (head == nullptr)
        return nullptr;

    unordered_map<int, ListNode *> sumMap;
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    int sum = 0;
    sumMap[sum] = dummy;

    while (head != nullptr)
    {
        sum += head->val;

        if (sumMap.find(sum) != sumMap.end())
        {
            ListNode *prev = sumMap[sum];
            ListNode *curr = prev->next;

            int tempSum = sum;
            while (curr != head)
            {
                tempSum += curr->val;
                sumMap.erase(tempSum);
                curr = curr->next;
            }

            prev->next = head->next;
        }
        else
        {
            sumMap[sum] = head;
        }

        head = head->next;
    }

    return dummy->next;
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

    ListNode *head = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(-3);
    ListNode *node4 = new ListNode(3);
    ListNode *node5 = new ListNode(1);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;

    // Remove zero sum consecutive nodes
    head = removeZeroSumSublists(head);

    // Print the updated linked list
    printLinkedList(head);

    return 0;
}
