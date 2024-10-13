#include <iostream>
using namespace std;

// Definition for singly-linked list node.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {} // Constructor to initialize the node
};

// Function to reverse the linked list
ListNode *reverseList(ListNode *head)
{
    ListNode *current = head;
    ListNode *prev = NULL;
    ListNode *next = NULL;

    while (current != NULL)
    {
        next = current->next; // Store the next node
        current->next = prev; // Reverse the current node's pointer
        prev = current;       // Move 'prev' one step forward
        current = next;       // Move 'current' one step forward
    }

    return prev; // 'prev' will be the new head of the reversed list
}

// Function to detect a cycle in the linked list using Floyd's Cycle Detection Algorithm
bool detectCycle(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return false;
    }

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;       // Move slow pointer by 1 step
        fast = fast->next->next; // Move fast pointer by 2 steps

        if (slow == fast)
        {
            return true; // Cycle detected
        }
    }
    return false; // No cycle detected
}

// Function to find the middle node of the linked list
ListNode *findMiddle(ListNode *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;       // Move slow pointer by 1 step
        fast = fast->next->next; // Move fast pointer by 2 steps
    }

    return slow; // Slow pointer will be at the middle
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
    ListNode *head = NULL;

    // Inserting nodes into the linked list
    insertNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 3);
    insertNode(head, 4);
    insertNode(head, 5);

    cout << "Original List: ";
    printList(head); // Print original list

    // Reverse the linked list
    ListNode *reversedHead = reverseList(head);

    cout << "Reversed List: ";
    printList(reversedHead); // Print reversed list

    // Detect a cycle in the linked list
    bool hasCycle = detectCycle(reversedHead);
    cout << "Cycle Detected: " << (hasCycle ? "Yes" : "No") << endl;

    // Find the middle of the linked list
    ListNode *middle = findMiddle(reversedHead);
    if (middle != NULL)
    {
        cout << "Middle of the list: " << middle->val << endl;
    }
    else
    {
        cout << "The list is empty." << endl;
    }

    return 0;
}
