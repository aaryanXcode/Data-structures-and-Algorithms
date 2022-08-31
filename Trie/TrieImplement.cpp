#include<iostream>
#include<string>
using namespace std;
class TrieNode
{
    public:
    char data;
    TrieNode **children;
    bool isTerminal;
    TrieNode(char data)
    {
        this->data=data;
        children=new TrieNode*[26];
        for(int i=0;i<26;i++)
        {
            children[i]=NULL;
        }
        isTerminal=false;
    }


};
class Trie
{
    TrieNode *root;
public:
    Trie()
    {
        root=new TrieNode('\0');
    }

    //inserting
    void insertWord(TrieNode *root,string word)
    {
        //base condition
        if(word.size()==0)
        {
            root->isTerminal=true;
            return;
        }
        //small calculation
        int index=word[0]-'a';
        TrieNode *child;
        if(root->children!=NULL)
        {
            child=root->children[index];
        }
        else
        {
            child=new TrieNode(word[0]);
            root->children[index]=child;
        }
        insertWord(child,word.substr(1));

    }

    //searching
    bool searchWord(TrieNode *root,string word)
    {
        //base condition
        if(word.size()==0)
        {
            return root->isTerminal;
        }
        int index=word[0]-'a';
        TrieNode *child;
        if(root->children[index]!=NULL)
        {
            child=root->children[index];
        }
        else
        {
            return false;
        }
        return searchWord(child,word.substr(1));
    }

    //delete
    void removeWord(TrieNode*root,string word)
    {
        //base case
        if(word.size()==0)
        {
            root->isTerminal=false;
            return;
        }
        //small calculation
        TrieNode * child;
        int index=word[0]-'a';
        if(root->children[index]!=NULL)
        {
            child=root->children[index];
        }
        else
        {
            //word not found
            return ;
        }
        removeWord(child,word.substr(1));
        //remove childNode it is useless
        if(child->isTerminal==false)
        {
            for(int i=0;i<26;i++)
            {
                if(child->children[i]!=NULL)
                {
                    return ;
                }
            }
            delete child;
            root->children[index]=NULL;
        }
    }
    //for user
    void insertWord(string word)
    {
        insertWord(root,word);
    }
    bool searchWord(string word)
    {
        return searchWord(root,word);
    }
    void removeWord(string word)
    {
        removeWord(root,word);
    }
};
int main()
{
    Trie *t=new Trie();
    t->insertWord("and");
    t->insertWord("are");
    t->insertWord("dot");
    if(t->searchWord("and"))
    {
        cout<<"True"<<endl;
    }
    else
    {
        cout<<"false"<<endl;
    }

}
