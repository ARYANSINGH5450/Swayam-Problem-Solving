class Solution {
public:
    struct trie{
        trie* child[26];
        bool flag;
        trie()
        {
            for(int i=0;i<26;i++)
            {
                child[i]=nullptr;
            }
            flag=false;
        }
    };
    trie* root=new trie();
    string replaceWords(vector<string>& dictionary, string sentence) {
        trie* head;
        for(int i=0;i<dictionary.size();i++)
        {
            head=root;
            for(int j=0;j<dictionary[i].size();j++)
            {
                char c=dictionary[i][j];
                if(head->child[c-'a']==NULL)
                {
                    head->child[c-'a']=new trie();
                }
                head=head->child[c-'a'];
            }
            head->flag=true;
        }
        head=root;
        int i=0;
        string ans;
        while(i<sentence.size())
        {
            if(sentence[i]!=' ')
            {
                if(head->child[sentence[i]-'a'])
                {
                    ans+=sentence[i];
                    head=head->child[sentence[i]-'a'];
                    i++;
                    if(head->flag)
                    {
                         while(i<sentence.size()&&sentence[i]!=' ')
                        {
                           i++;
                        }
                    }
                }
                else
                {
                    while(sentence[i]!=' '&&i<sentence.size())
                    {
                        ans+=sentence[i];
                        i++;
                    }
                }
            }
            else
            {
                ans+=' ';
                i++;
                head=root;
            }
        }
        return ans;
    }
};
