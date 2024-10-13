#include <iostream>
#include <climits>
using namespace std;

class MinStack
{
    int *stackArray;
    int *minArray; // Array to keep track of minimum values
    int topIndex;
    int minTopIndex;
    int capacity;

public:
    // Constructor to initialize the stack with a given capacity
    MinStack(int size)
    {
        capacity = size;
        stackArray = new int[capacity];
        minArray = new int[capacity];
        topIndex = -1;
        minTopIndex = -1;
    }

    // Push an element onto the stack
    void push(int value)
    {
        if (topIndex >= capacity - 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }

        // Push element into stackArray
        stackArray[++topIndex] = value;

        // Push to minArray if it's the first element or a new minimum
        if (minTopIndex == -1 || value <= minArray[minTopIndex])
        {
            minArray[++minTopIndex] = value;
        }
    }

    // Pop the top element from the stack
    void pop()
    {
        if (topIndex == -1)
        {
            cout << "Stack Underflow" << endl;
            return;
        }

        // If the top of the main stack is the same as the top of the min stack, pop from both
        if (stackArray[topIndex] == minArray[minTopIndex])
        {
            --minTopIndex;
        }
        --topIndex;
    }

    // Get the top element from the stack
    int top()
    {
        if (topIndex == -1)
        {
            cout << "Stack is Empty" << endl;
            return INT_MIN;
        }
        return stackArray[topIndex];
    }

    // Retrieve the minimum element from the stack
    int getMin()
    {
        if (minTopIndex == -1)
        {
            cout << "Stack is Empty" << endl;
            return INT_MIN;
        }
        return minArray[minTopIndex];
    }

    // Destructor to clean up dynamically allocated memory
    ~MinStack()
    {
        delete[] stackArray;
        delete[] minArray;
    }
};

int main()
{
    MinStack s(5);

    s.push(3);
    s.push(5);
    cout << "Current Minimum: " << s.getMin() << endl; // Output: 3

    s.push(2);
    s.push(1);
    cout << "Current Minimum: " << s.getMin() << endl; // Output: 1

    s.pop();
    cout << "Current Minimum after popping: " << s.getMin() << endl; // Output: 2

    s.pop();
    cout << "Top element: " << s.top() << endl;        // Output: 5
    cout << "Current Minimum: " << s.getMin() << endl; // Output: 3

    return 0;
}
