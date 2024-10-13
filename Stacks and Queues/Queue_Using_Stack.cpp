#include <iostream>
#include <stack>
using namespace std;

class QueueUsingStacks
{
    stack<int> inputStack;  // Stack used for enqueue
    stack<int> outputStack; // Stack used for dequeue

public:
    // Enqueue an element to the queue
    void enqueue(int value)
    {
        inputStack.push(value);
        cout << value << " enqueued into the queue." << endl;
    }

    // Dequeue an element from the queue
    int dequeue()
    {
        // If outputStack is empty, transfer all elements from inputStack
        if (outputStack.empty())
        {
            if (inputStack.empty())
            {
                cout << "Queue is Empty" << endl;
                return -1; // Queue is empty
            }
            while (!inputStack.empty())
            {
                outputStack.push(inputStack.top());
                inputStack.pop();
            }
        }
        int dequeuedValue = outputStack.top();
        outputStack.pop();
        return dequeuedValue;
    }

    // Get the front element of the queue
    int front()
    {
        if (outputStack.empty())
        {
            if (inputStack.empty())
            {
                cout << "Queue is Empty" << endl;
                return -1;
            }
            while (!inputStack.empty())
            {
                outputStack.push(inputStack.top());
                inputStack.pop();
            }
        }
        return outputStack.top();
    }

    // Check if the queue is empty
    bool isEmpty()
    {
        return inputStack.empty() && outputStack.empty();
    }
};

int main()
{
    QueueUsingStacks q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.front() << endl; // Output: 10

    cout << q.dequeue() << " dequeued from the queue." << endl; // Output: 10
    cout << "Front element: " << q.front() << endl;             // Output: 20

    cout << q.dequeue() << " dequeued from the queue." << endl; // Output: 20
    cout << "Front element: " << q.front() << endl;             // Output: 30

    return 0;
}
