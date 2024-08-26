#include<iostream>
using namespace std;
class Node
{
    public:
        int data;
        Node* next;

        //constructor
        Node(int d)
        {
            this->data = d;
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
            cout<<"Memory is free for the node with data "<<value<<endl;
        }
};
void insertNode(Node* &tail,int element, int d)
{

    //empty list
    if(tail == NULL)
    {
        Node* newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    else{
        //Non empty list
        //assuming that the element is present in the list

        Node* curr = tail;
        
        while(curr->data != element)
        {
            curr = curr->next;
        }

        //element found curr is representing element
        Node* temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}
//deleting a node
void deleteNode(Node* &tail,int value)
{
    //empty list
    if(tail == NULL)
    {
        cout<<"List is empty, please check again"<<endl;
        return ;
    }
    else{
        //non empty list
        //assuming that value is present in the list
        Node* prev = tail;
        Node* curr = prev->next;
        while(curr->data != value)
        {
            prev = curr;
            curr = curr->next;
        }

        prev->next = curr->next;
        //for one node linked list
        if(curr == prev)
            tail = NULL;
        //>=2 node linked list
        else if(tail == curr)
            tail = prev;
        
        curr->next = NULL;
        delete curr;
    }

}
//traversing the list through tail
void print(Node* tail)
{
    Node* temp = tail;
    if(tail == NULL){
        cout<<"List is empty "<<endl;
        return;
    }    
    do{
        cout<<tail->data<<" ";
        tail = tail->next;
    }while(tail != temp);

    cout<<endl;
}

void breakIntoTwo(Node *head)
{
    Node *temp = head;
    Node *head1,*p;
    Node *head2,*q;
    int count = 1;

    while(temp->next != head)
    {
        count++;
        temp = temp->next;
    }

    cout<<"Length of list-> "<<count<<endl;

    temp = head;
    int pos1 = count/2;
    int pos2 = count - pos1;
    int i=1,j=1;

    head1 = temp;

    while(i < pos1)
    {
        //cout<<temp->data<<" ";
        temp = temp->next;
        i++;
    }
    //cout<<endl;
    p = temp;
    head2 = temp->next;
    p->next = head1;
    q = head2;

    while(j < pos2)
    {
        //cout<<q->data<<" ";
        q = q->next;
        j++;
    }
    cout<<endl;
    q->next = head2;

    print(head1);
    print(head2);
}

int main()
{
    Node* tail= NULL;

    insertNode(tail,5,3);
    print(tail);

    insertNode(tail,3,5);
    print(tail);

    insertNode(tail,5,7);
    print(tail);

    insertNode(tail,7,9);
    print(tail);

    insertNode(tail,5,6);
    print(tail);

    insertNode(tail,9,10);
    print(tail);

    // insertNode(tail,3,4);
    // print(tail);



    // deleteNode(tail,5);
    // print(tail);

    breakIntoTwo(tail);
    
    return 0;
}