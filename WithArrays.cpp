#include <iostream>

using namespace std;

const int MAX_SIZE = 100;

struct Stack
{
    int data[MAX_SIZE];
    int top = -1;

    void push(int x)
    {
        if (top == MAX_SIZE - 1)
        {
            cout << "Stack is full\n";
            return;
        }
        data[++top] = x;
    }

    int pop()
    {
        if (top == -1)
        {
            cout << "Stack is empty\n";
            return -1; 
        }
        return data[top--];
    }

    void print()
    {
        cout << "Stack:\n";
        for (int i = top; i >= 0; i--)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

struct Queue
{
    int data[MAX_SIZE];
    int front = 0;
    int rear = -1;
    int itemCount = 0;

    void push(int x)
    {
        if (itemCount == MAX_SIZE)
        {
            cout << "Queue is full\n";
            return;
        }
        if (rear == MAX_SIZE - 1)
            rear = -1;
        data[++rear] = x;
        itemCount++;
    }

    int pop()
    {
        if (itemCount == 0)
        {
            cout << "Queue is empty\n";
            return -1;
        }
        int x = data[front++];
        if (front == MAX_SIZE)
            front = 0;
        itemCount--;
        return x;
    }

    void print()
    {
        cout << "Queue:\n";
        int i = front;
        int count = 0;
        while (count < itemCount)
        {
            cout << data[i++] << " ";
            if (i == MAX_SIZE)
                i = 0;
            count++;
        }
        cout << endl;
    }
};

int main()
{
    Stack stack;
    Queue queue;

    for (int i = 3; i <= 55; i += 2)
        queue.push(i);

    queue.print();

    while (queue.itemCount > 0)
    {
        stack.push(queue.pop());
    }

    cout << "Stack numbers devidable by 3:\n";
    while (stack.top != -1)
    {
        int num = stack.pop();
        if (num % 3 == 0)
            cout << num << " ";
    }
    cout << endl;

    return 0;
}
