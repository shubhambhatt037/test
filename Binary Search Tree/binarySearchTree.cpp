#include<iostream>
#include<queue>
using namespace std;

class Node
{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertAtTree(Node* root, int d)
{
    if(!root)
    {
        root = new Node(d);
        return root;
    }

    if(d > root->data)
        root->right = insertAtTree(root->right, d);
    else
        root->left = insertAtTree(root->left, d);
    
    return root;
}

void createTree(Node* &root)
{
    cout<<"Enter data for the tree-> ";
    int d;
    cin>>d;

    while(d != -1)
    {
        root = insertAtTree(root, d);
        cin>>d;
    }
}

void levelOrderTraversal(Node* root)
{
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL)
        {
            //one level is completely traversed
            cout<<endl;
            if(!q.empty())
            {
                //child nodes are present
                q.push(NULL);
            }
        }
        else
        {
            cout<< temp -> data <<" ";
            if(temp -> left)
                q.push(temp -> left);
            
            if(temp -> right)
                q.push(temp -> right);
        }
    }
}

void preorder(Node* root)
{
    if(!root) //Base case
        return;
    
    cout<< root -> data <<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root)
{
    if(!root) //Base case
        return;
    
    inorder(root->left);
    cout<< root -> data <<" ";
    inorder(root->right);
}

void postorder(Node* root)
{
    if(!root) //Base case
        return;
    
    postorder(root->left);
    postorder(root->right);
    cout<< root -> data <<" ";
}

Node* inorderPredecessor(Node* curr)
{
    Node* pre = curr->left;
    while(pre->right)
    {
        pre = pre->right;
    }
    return pre;
}

Node* deleteFromBST(Node* &root, int d)
{
    if(!root)
        return NULL;
    
    if(!root->left && !root->right)
    {
        delete root;
        return NULL;
    }

    if(root->data > d)
        root->left = deleteFromBST(root->left, d);
    else if(root->data < d)
        root->right = deleteFromBST(root->right, d);
    else 
    {
        Node* pre = inorderPredecessor(root);
        root->data = pre->data;
        root->left = deleteFromBST(root->left, pre->data);
    }
    return root;
}

int main()
{
    Node* root = NULL;
    createTree(root);

    // cout<<"Level order traversal is-> "<<endl;
    // levelOrderTraversal(root);

    // cout<<endl<<"Printing preorder-> "<<endl;
    // preorder(root);

    cout<<endl<<"Deleting a node-> "<<endl;
    deleteFromBST(root, 5);
    cout<<endl<<"Printing inorder-> "<<endl;
    inorder(root);

    // cout<<endl<<"Printing postorder-> "<<endl;
    // postorder(root);

    return 0;
}