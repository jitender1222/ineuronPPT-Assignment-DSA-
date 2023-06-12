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

Node *mergeLists(Node *list1, Node *list2)
{
    if (list1 == nullptr)
        return list2;
    if (list2 == nullptr)
        return list1;

    Node *newList = nullptr;
    Node *tail = nullptr;

    while (list1 != nullptr && list2 != nullptr)
    {
        if (list1->data > list2->data)
        {
            if (newList == nullptr)
            {
                newList = tail = list1;
            }
            else
            {
                tail->next = list1;
                tail = tail->next;
            }
            list1 = list1->next;
        }
        else
        {
            if (newList == nullptr)
            {
                newList = tail = list2;
            }
            else
            {
                tail->next = list2;
                tail = tail->next;
            }
            list2 = list2->next;
        }
    }

    if (list1 != nullptr)
        tail->next = list1;
    if (list2 != nullptr)
        tail->next = list2;

    return newList;
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
    // Example 1
    Node *list1 = createNode(5);
    list1->next = createNode(2);
    list1->next->next = createNode(3);
    list1->next->next->next = createNode(8);

    Node *list2 = createNode(1);
    list2->next = createNode(7);
    list2->next->next = createNode(4);
    list2->next->next->next = createNode(5);

    cout << "Input: list1 = ";
    displayList(list1);
    cout << "list2 = ";
    displayList(list2);

    Node *newList = mergeLists(list1, list2);

    cout << "Output: New list = ";
    displayList(newList);

    // Example 2
    Node *list3 = createNode(2);
    list3->next = createNode(8);
    list3->next->next = createNode(9);
    list3->next->next->next = createNode(3);

    Node *list4 = createNode(5);
    list4->next = createNode(3);
    list4->next->next = createNode(6);
    list4->next->next->next = createNode(4);

    cout << "\nInput: list1 = ";
    displayList(list3);
    cout << "list2 = ";
    displayList(list4);

    Node *newList2 = mergeLists(list3, list4);

    cout << "Output: New list = ";
    displayList(newList2);

    return 0;
}
