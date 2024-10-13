#include <iostream>
using namespace std;

// Definition for singly-linked list node.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {} // Constructor to initialize the node
};

// Function to merge two sorted linked lists
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
{
    // Create a dummy node to act as the start of the merged list
    ListNode *dummy = new ListNode(0);
    ListNode *current = dummy;

    // Loop while both lists are non-empty
    while (l1 != NULL && l2 != NULL)
    {
        if (l1->val <= l2->val)
        {
            current->next = l1; // Link l1 node
            l1 = l1->next;      // Move l1 forward
        }
        else
        {
            current->next = l2; // Link l2 node
            l2 = l2->next;      // Move l2 forward
        }
        current = current->next; // Move current pointer forward
    }

    // If there are remaining nodes in either list, link them
    if (l1 != NULL)
    {
        current->next = l1;
    }
    else
    {
        current->next = l2;
    }

    return dummy->next; // The merged list starts at dummy->next
}

// Function to insert a node at the end of the linked list
void insertNode(ListNode *&head, int val)
{
    ListNode *newNode = new ListNode(val);
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    ListNode *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to print the linked list
void printList(ListNode *head)
{
    ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    // Create two sorted linked lists
    ListNode *l1 = NULL;
    insertNode(l1, 1);
    insertNode(l1, 2);
    insertNode(l1, 4);

    ListNode *l2 = NULL;
    insertNode(l2, 1);
    insertNode(l2, 3);
    insertNode(l2, 5);

    cout << "List 1: ";
    printList(l1); // Print first sorted list

    cout << "List 2: ";
    printList(l2); // Print second sorted list

    // Merge the two sorted linked lists
    ListNode *mergedList = mergeTwoLists(l1, l2);

    cout << "Merged List: ";
    printList(mergedList); // Print the merged sorted list

    return 0;
}
