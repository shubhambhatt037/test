 #include<iostream>
 #include<queue>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;
    
    node(int d)
    {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

node* buildTree(node* root) 
{
    cout<<"Enter the data-> "<<endl;
    int data;
    cin>>data;
    root = new node(data);

    if(data == -1)
        return NULL;
    
    cout<<"Enter data for inserting in left of "<<data <<endl;
    root->left = buildTree(root->left);
    cout<<"Enter data for inserting in right of "<<data <<endl;
    root->right = buildTree(root->right);

    return root;
}

void levelOrderTraversal(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        node* temp = q.front();
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

void buildFromLevelOrder(node* &root)
{
    queue<node*> q;
    cout<<"Enter data for root"<<endl;
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);

    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();

        cout<<"Enter left node for: "<<temp->data<<endl;
        int leftdata;
        cin >> leftdata;

        if(leftdata != -1)
        {
            temp->left = new node(leftdata);
            q.push(temp->left);
        }

        cout<<"Enter right node for: "<<temp->data<<endl;
        int rightdata;
        cin >> rightdata;

        if(rightdata != -1)
        {
            temp->right = new node(rightdata);
            q.push(temp->right);
        }
    }
}

void preorder(node* root)
{
    if(!root) //Base case
        return;
    
    cout<< root -> data <<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(node* root)
{
    if(!root) //Base case
        return;
    
    inorder(root->left);
    cout<< root -> data <<" ";
    inorder(root->right);
}

void postorder(node* root)
{
    if(!root) //Base case
        return;
    
    postorder(root->left);
    postorder(root->right);
    cout<< root -> data <<" ";
}

int height(struct node* node)
{
    if(!node)
        return 0;
        
    int leftheight = height(node->left);
    int rightheight = height(node->right);
    
    // int ans = max(leftheight, rightheight) + 1;
    // return ans;
    if(leftheight > rightheight)
        return leftheight + 1;
    else
        return rightheight + 1;
    
}

int main()
{
    node* root = NULL;

    //building from level order
    buildFromLevelOrder(root);
    cout<<"Level Order Traversal: "<<endl;
    levelOrderTraversal(root);

    // //creating a binary tree
    // root = buildTree(root);

    // //level order traversal
    // cout<<"Printing Level Order Traversal output "<<endl;
    // levelOrderTraversal(root);

    // //preorder traversal
    // cout<<"Printing PreOrder Traversal output "<<endl;
    // preorder(root);
    // cout<<endl;

    // //inorder traversal
    // cout<<"Printing inOrder Traversal output "<<endl;
    // inorder(root);
    // cout<<endl;

    // //postorder traversal
    // cout<<"Printing PostOrder Traversal output "<<endl;
    // postorder(root);
    // cout<<endl;

    return 0;
}