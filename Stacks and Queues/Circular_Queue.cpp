#include <iostream>
using namespace std;

class CircularQueue
{
    int *queueArray;
    int front;
    int rear;
    int size;
    int capacity;

public:
    // Constructor to initialize the queue with a given capacity
    CircularQueue(int cap)
    {
        capacity = cap;
        queueArray = new int[capacity];
        front = -1;
        rear = -1;
        size = 0;
    }

    // Check if the queue is full
    bool isFull()
    {
        return size == capacity;
    }

    // Check if the queue is empty
    bool isEmpty()
    {
        return size == 0;
    }

    // Add an element to the circular queue
    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "Queue is Full" << endl;
            return;
        }

        // First element being inserted
        if (isEmpty())
        {
            front = 0;
        }

        // Move rear in a circular manner
        rear = (rear + 1) % capacity;
        queueArray[rear] = value;
        size++;
        cout << value << " enqueued into the queue." << endl;
    }

    // Remove an element from the circular queue
    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return -1;
        }

        int dequeuedValue = queueArray[front];
        front = (front + 1) % capacity; // Move front in a circular manner
        size--;

        // If the queue becomes empty after dequeuing, reset front and rear
        if (isEmpty())
        {
            front = -1;
            rear = -1;
        }

        return dequeuedValue;
    }

    // Get the front element of the queue
    int getFront()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        return queueArray[front];
    }

    // Get the rear element of the queue
    int getRear()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        return queueArray[rear];
    }

    // Destructor to free memory
    ~CircularQueue()
    {
        delete[] queueArray;
    }
};

int main()
{
    CircularQueue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    cout << "Front element: " << q.getFront() << endl; // Output: 10
    cout << "Rear element: " << q.getRear() << endl;   // Output: 50

    q.dequeue();
    cout << "After dequeue, front element: " << q.getFront() << endl; // Output: 20

    q.enqueue(60);                                                     // This will wrap around to the beginning
    cout << "After enqueue 60, rear element: " << q.getRear() << endl; // Output: 60

    return 0;
}
