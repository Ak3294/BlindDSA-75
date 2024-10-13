#include <iostream>
using namespace std;

// Node structure for linked list
struct Node
{
    int data;   // Data stored in the node
    Node *next; // Pointer to the next node

    // Constructor to initialize a new node
    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

// Stack class using a linked list
class Stack
{
private:
    Node *top; // Pointer to the top of the stack

public:
    // Constructor to initialize an empty stack
    Stack()
    {
        top = NULL;
    }

    // Push function to add an element to the top of the stack
    void push(int value)
    {
        Node *newNode = new Node(value); // Create a new node
        newNode->next = top;             // Point the new node to the current top
        top = newNode;                   // Update top to the new node
    }

    // Pop function to remove and return the top element from the stack
    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow!" << endl;
            return -1; // Return -1 if stack is empty
        }
        int poppedValue = top->data; // Store the data from the top
        Node *temp = top;            // Temporary pointer to the current top
        top = top->next;             // Move top to the next node
        delete temp;                 // Delete the old top node
        return poppedValue;          // Return the popped value
    }

    // Peek function to return the top element without removing it
    int peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
            return -1; // Return -1 if stack is empty
        }
        return top->data; // Return the data of the top node
    }

    // Function to check if the stack is empty
    bool isEmpty()
    {
        return top == NULL;
    }

    // Function to display the contents of the stack
    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty!" << endl;
            return;
        }
        Node *temp = top;
        cout << "Stack elements: ";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Stack stack; // Create a stack

    // Push elements into the stack
    stack.push(10);
    stack.push(20);
    stack.push(30);

    // Display the stack
    stack.display(); // Output: Stack elements: 30 20 10

    // Peek the top element
    cout << "Top element is: " << stack.peek() << endl; // Output: 30

    // Pop the top element
    cout << "Popped element is: " << stack.pop() << endl; // Output: 30

    // Display the stack after pop
    stack.display(); // Output: Stack elements: 20 10

    // Peek the new top element
    cout << "Top element is: " << stack.peek() << endl; // Output: 20

    // Pop all elements
    cout << "Popped element is: " << stack.pop() << endl; // Output: 20
    cout << "Popped element is: " << stack.pop() << endl; // Output: 10

    // Try to pop from an empty stack
    stack.pop(); // Output: Stack Underflow!

    // Check if the stack is empty
    cout << "Is stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl; // Output: Yes

    return 0;
}
