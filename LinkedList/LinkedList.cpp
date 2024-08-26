#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    //destructor
    ~Node()
    {
        int value = this->data;
        //memory free
        if(this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout<<"Memory is free for the node with data-> "<<value<<endl;
    }
};
void InsertAtHead(Node *&head, int d)
{
    // new node create
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void InsertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void InsertAtPosition(Node *&head, Node *&tail, int position, int d)
{
    // Insert at start
    if (position == 1)
    {
        InsertAtHead(head, d);
        return;
    }

    Node *temp = head;
    int count = 1;

    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }

    // Insert at end
    if (temp->next == NULL)
    {
        InsertAtTail(tail, d);
        return;
    }
    // creating a node for d
    Node *nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void deleteNode(Node* &head ,Node* &tail ,int position)
{
    if(position == 1)
    {
        Node *temp = head;
        head = head->next;
        //delete first node
        temp->next = NULL;
        delete temp;
    }else{
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position)
        {
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        if(prev->next == NULL)
            tail = prev;
        curr->next = NULL;
        delete curr;
    }
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *floydDetectLoop(Node *head)
{
    // Write your code here.
    if(head == NULL)
        return NULL;

    Node *slow = head;
    Node *fast = head->next;
    while(slow != fast && fast != NULL && slow != NULL)
    {
        fast = fast->next;
        if(fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;
    }
    if(fast == slow)
    {
        cout<<"Cycle is present at -> "<<slow->data<<endl;
        return slow;
    }
        
    return NULL;
}

Node *getStartingNode(Node *head)
{
    if(head == NULL)
        return NULL;
    
    Node *intersection = floydDetectLoop(head);
    Node *slow = head;
    while(slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }

    return slow;
}

int main()
{
    Node *node1 = new Node(10);
    // cout<<node1->data<<endl;
    // cout<<node1->next<<endl;

    // head pointed to node 1
    Node *head = node1;
    /*print(head);

    InsertAtHead(head,12);
    print(head);

    InsertAtHead(head,15);
    print(head);*/

    Node *tail = node1;
    print(head);

    InsertAtTail(tail, 12);
    print(head);

    InsertAtTail(tail, 15);
    print(head);

    InsertAtPosition(head, tail, 3, 22);
    print(head);

    cout << "Head " << head->data << endl;
    cout << "Tail " << tail->data << endl;

    deleteNode(head,tail,4);
    print(head);

    cout << "Head " << head->data << endl;
    cout << "Tail " << tail->data << endl;

    if(floydDetectLoop(head) != NULL)
        cout<<"Loop is present in -> "<<floydDetectLoop(head)->data<<endl;
    else
        cout<<"Loop not present"<<endl;

    return 0;
}