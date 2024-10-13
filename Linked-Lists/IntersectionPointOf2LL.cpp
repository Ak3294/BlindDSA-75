#include <iostream>
using namespace std;

// Definition for singly-linked list node.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {} // Constructor to initialize the node
};

// Function to find the intersection point of two linked lists
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    if (headA == NULL || headB == NULL)
    {
        return NULL; // If either list is empty, there's no intersection
    }

    // Initialize two pointers
    ListNode *p1 = headA;
    ListNode *p2 = headB;

    // Traverse both lists
    while (p1 != p2)
    {
        // Move p1 and p2 one step forward, and switch to the other list if reaching the end
        p1 = (p1 == NULL) ? headB : p1->next;
        p2 = (p2 == NULL) ? headA : p2->next;
    }

    // If they meet, p1 or p2 will point to the intersection node
    // If no intersection, both will be NULL
    return p1;
}

// Helper function to insert a node at the end of the linked list
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
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    // Create two linked lists with an intersection point
    ListNode *headA = NULL;
    ListNode *headB = NULL;

    // List A: 1 -> 9 -> 1
    insertNode(headA, 1);
    insertNode(headA, 9);
    insertNode(headA, 1);

    // List B: 3
    insertNode(headB, 3);

    // Common nodes: 2 -> 4
    ListNode *common = new ListNode(2);
    common->next = new ListNode(4);

    // Append common nodes to both lists
    headA->next->next->next = common; // List A: 1 -> 9 -> 1 -> 2 -> 4
    headB->next = common;             // List B: 3 -> 2 -> 4

    // Print both lists
    cout << "List A: ";
    printList(headA);

    cout << "List B: ";
    printList(headB);

    // Find the intersection node
    ListNode *intersection = getIntersectionNode(headA, headB);

    if (intersection)
    {
        cout << "Intersection at node with value: " << intersection->val << endl;
    }
    else
    {
        cout << "No intersection." << endl;
    }

    return 0;
}
