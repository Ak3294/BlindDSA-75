#include <iostream>
using namespace std;

class MaxStack
{
    int *stackArray;
    int *maxArray; // Array to keep track of the maximum values
    int topIndex;
    int maxTopIndex;
    int capacity;

public:
    // Constructor to initialize the stack with a given capacity
    MaxStack(int size)
    {
        capacity = size;
        stackArray = new int[capacity];
        maxArray = new int[capacity];
        topIndex = -1;
        maxTopIndex = -1;
    }

    // Push an element onto the stack
    void push(int value)
    {
        if (topIndex >= capacity - 1)
        {
            cout << "Stack Overflow" << endl;
            return;
        }

        // Push the element into the stackArray
        stackArray[++topIndex] = value;

        // If it's the first element or greater than the current max, push to maxArray
        if (maxTopIndex == -1 || value >= maxArray[maxTopIndex])
        {
            maxArray[++maxTopIndex] = value;
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

        // If the top of the main stack is equal to the top of the max stack, pop from both
        if (stackArray[topIndex] == maxArray[maxTopIndex])
        {
            --maxTopIndex;
        }
        --topIndex;
    }

    // Get the top element from the stack
    int top()
    {
        if (topIndex == -1)
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return stackArray[topIndex];
    }

    // Get the maximum element from the stack
    int getMax()
    {
        if (maxTopIndex == -1)
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return maxArray[maxTopIndex];
    }

    // Destructor to free memory
    ~MaxStack()
    {
        delete[] stackArray;
        delete[] maxArray;
    }
};

int main()
{
    MaxStack s(5);

    s.push(3);
    s.push(5);
    cout << "Current Maximum: " << s.getMax() << endl; // Output: 5

    s.push(7);
    s.push(19);
    cout << "Current Maximum: " << s.getMax() << endl; // Output: 19

    s.pop();
    cout << "Current Maximum after popping: " << s.getMax() << endl; // Output: 7

    cout << "Top element: " << s.top() << endl; // Output: 7

    s.pop();
    cout << "Current Maximum: " << s.getMax() << endl; // Output: 5

    return 0;
}
