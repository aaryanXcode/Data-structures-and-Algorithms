class Trie
{
    TrieNode *root;
public:
    Trie()
    {
        root=new TrieNode('\0');
    }
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
    bool searchWord(TrieNode *root,string word)
    {
        //base condition
        if (word.size() == 0)
        {
            if (root->isTerminal == true)
            {
                return true;
            }
            return false;
        }
        //small calculation
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
        searchWord(child,word.substr(1));

    }
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

    void insertWord(string word)
    {
        insertWord(root,word);
    }
    void searchWord(string word)
    {
        searchWord(root,word);
    }
    bool removeWord(string word)
    {
        removeWord(root,word);
    }
};
