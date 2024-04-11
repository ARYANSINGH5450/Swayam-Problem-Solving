struct trienode{
    trienode* child[26];
    bool flag;
    trienode()
    {
        for(int i=0;i<26;i++)
        {
            child[i]=nullptr;
        }
        flag=false;
    }
};
class Trie {
public:
    trienode* root;
    Trie() {
        root=new trienode();
    }
    
    void insert(string word) {
        trienode* head=root;
        for(int i=0;i<word.size();i++)
        {
           if(head->child[word[i]-'a']==NULL)
           {
               head->child[word[i]-'a']=new trienode();
           }
           head=head->child[word[i]-'a'];
        }
        head->flag=true;
    }
    
    bool search(string word) {
        trienode* head=root;
        for(int i=0;i<word.size();i++)
        {
           if(head->child[word[i]-'a']==NULL)
           {
               return false;
           }
           else 
           {
               head=head->child[word[i]-'a'];
           }
        }
        if(head->flag==false)
        {
            return false;
        }
        return true;
    }
    
    bool startsWith(string prefix) {
        trienode* head=root;
        for(int i=0;i<prefix.size();i++)
        {
           if(head->child[prefix[i]-'a']==NULL)
           {
               return false;
           }
           else 
           {
               head=head->child[prefix[i]-'a'];
           }
        }
        return true;
    }
};
