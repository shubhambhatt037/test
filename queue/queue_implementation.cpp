#include<iostream>
using namespace std;

class Queue {
public:
    int *arr;
    int qfront;
    int rear;
    int size;
    
    Queue() {
        int size = 100001;
        arr = new int[size];
        qfront = 0;
        rear = 0;
    }

    bool isEmpty() {
        if(qfront == rear)
            return true;
        else 
            return false;
    }

    void enqueue(int data) {
        if(rear == size)
            cout<<"Queue is full";
        else
        {
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue() {
        if(qfront == rear)
            return -1;
        else
        {
            int num = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            if(qfront == rear)
            {
                qfront = 0;
                rear = 0;
            }
            return num;
        }
    }

    int front() {
        if(qfront == rear)
            return -1;
        else
            return arr[qfront];
    }
};

int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(12);
    q.enqueue(14);
    cout<<q.dequeue()<<endl;
    cout<<q.front()<<endl;;
    cout<<q.isEmpty()<<endl;
    return 0;
}