#include<iostream>
#include<queue>
using namespace std;

int main()
{
    // queue<int> q;

    // q.push(10);
    // q.push(12);
    // q.push(14);

    // cout<<"Front of the queue is -> "<<q.front()<<endl;

    // q.pop();
    // q.pop();

    // cout<<"Number of element in queue is -> "<<q.size()<<endl;
    // if(q.empty())
    //     cout<<"Queue is empty"<<endl;
    // else 
    //     cout<<"Queue is not empty"<<endl;

    //Doubly ended queue

    deque<int> d;

    d.push_front(12);
    d.push_back(14);

    cout<<d.front()<<endl;
    cout<<d.back()<<endl;

    d.pop_front();

    cout<<d.front()<<endl;
    cout<<d.back()<<endl;
    d.pop_back();

    if(d.empty())
        cout<<"Queue is empty"<<endl;
    else
        cout<<"Queue not empty"<<endl;
    
    return 0;
}