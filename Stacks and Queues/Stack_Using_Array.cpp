#include <iostream>
using namespace std;

class Stack
{
    int top;
    int size;
    int *arr;

public:
    // Constructor to initialize stack
    Stack(int s)
    {
        size = s;
        arr = new int[size];
        top = -1;
    }

    // Push function to add an element
    void push(int value)
    {
        if (top >= size - 1)
        {
            cout << "Stack Overflow" << endl;
        }
        else
        {
            arr[++top] = value;
            cout << value << " pushed into the stack." << endl;
        }
    }

    // Pop function to remove an element
    int pop()
    {
        if (top < 0)
        {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        else
        {
            int value = arr[top--];
            cout << value << " popped from the stack." << endl;
            return value;
        }
    }

    // Peek function to view the top element
    int peek()
    {
        if (top < 0)
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        else
        {
            return arr[top];
        }
    }

    // Check if the stack is empty
    bool isEmpty()
    {
        return top < 0;
    }

    // Destructor to free memory
    ~Stack()
    {
        delete[] arr;
    }
};

int main()
{
    Stack s(5);

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.peek() << endl;

    s.pop();
    s.pop();
    s.pop();

    cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
