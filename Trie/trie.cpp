#include<iostream>
using namespace std;
class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;

    TrieNode(char ch)
    {
        data = ch;
        for(int i=0; i<26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

class Trie
{
    public:
    TrieNode* root;

    Trie()
    {
        root = new TrieNode('\0');
    }

    void insertUtil(TrieNode* root, string word)
    {
        // base case
        if(word.length()==0){
            root->isTerminal = true;
            return;
        }

        // assumption word will be in caps
        int index = word[0] - 'A';
        TrieNode* child;

        if(root-> children[index] != NULL)
            child = root->children[index];
        else
        {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        // Recursion
        insertUtil(child, word.substr(1));
    }

    void insertWord(string word)
    {
        insertUtil(root, word);
    }

    bool searchUtil(TrieNode* root, string word)
    {
        if(word.length() == 0)
            return root->isTerminal;

        int index = word[0] - 'A';
        TrieNode* child;

        if(root->children[index] != NULL)
            child = root->children[index];
        else
            return false;
        
        // Recursion
        return searchUtil(child, word.substr(1));
    }

    bool searchWord(string word)
    {
        return searchUtil(root, word);
    }

    bool deleteUtil(TrieNode* root, string word)
    {
        if(word.length() == 0)
        {
            root->isTerminal = false;
            // if the node has no children it can be deleted
            if(isEmpty(root))
            {
                delete root;
                return true;
            }
            return false;
        }

        int index = word[0] - 'A';
        TrieNode* child;

        if(root->children[index] != NULL)
            child = root->children[index];
        else
            return false;
        
        if(deleteUtil(child, word.substr(1)))
        {
            root->children[index] = NULL;
            if(isEmpty(root) && !root->isTerminal)
            {
                delete root;
                return true;
            }
        }

        return false;
    }

    bool deleteWord(string word)
    {
        return deleteUtil(root, word);
    }

    bool isEmpty(TrieNode* root)
    {
        for(int i=0; i< 26; i++)
        {
            if(root->children[i] != NULL)
                return false;
        }
        return true;
    }

};
int main()
{
    Trie *t = new Trie;
    
    t->insertWord("ARM");
    t->insertWord("DO");
    t->insertWord("TIME");
    cout<<"Present or not "<<t->searchWord("TIME")<<endl;
    t->deleteWord("TIME");
    cout<<"Present or not "<<t->searchWord("TIME")<<endl;

    return 0;
}


// struct Node{
//     bool isEnd = false;
//     Node* child[26];

//     bool isContain(char ch)
//     {
//         return (child[ch-'a'] != NULL);
//     }

//     void put(char ch, Node* node)
//     {
//         child[ch-'a'] = node;
//     }

//     void setEnd()
//     {
//         isEnd = true;
//     }

//     Node* get(char ch)
//     {
//         return child[ch-'a'];
//     }
    
// };

// class Trie {
//     Node* root;
// public:
//     Trie() {
//         root = new Node();
//     }
    
//     void insert(string word) {
        
//         Node* node = root;
//         for(int i=0; i<word.length(); i++)
//         {
//             if(!node->isContain(word[i]))
//                 node->put(word[i], new Node());
            
//             node = node->get(word[i]);
//         }

//         node->setEnd();
//     }
    
//     bool search(string word) {

//         Node* node = root;
//         for(int i=0; i<word.length(); i++)
//         {
//             if(!node->isContain(word[i]))   return false;

//             node = node->get(word[i]);
//         }

//         return node->isEnd;
//     }
    
//     bool startsWith(string prefix) {
        
//         Node* node = root;
//         for(int i=0; i<prefix.length(); i++)
//         {
//             if(!node->isContain(prefix[i]))   return false;
//             node = node->get(prefix[i]);
//         }

//         return true;
//     }
// };

