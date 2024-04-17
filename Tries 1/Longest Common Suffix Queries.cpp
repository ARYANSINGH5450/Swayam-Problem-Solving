class Solution {
public:
    struct trie{
        trie* child[26];
        bool flag;
        vector<int>ind;
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
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        trie* head;
        for(int i=0;i<wordsContainer.size();i++)
        {
            head=root;
            for(int j=wordsContainer[i].size()-1;j>=0;j--)
            {
                char c=wordsContainer[i][j];
                if(head->child[c-'a']==NULL)
                {
                    head->child[c-'a']=new trie();
                }
                head->child[c-'a']->ind.push_back(i);
                head=head->child[c-'a'];
            }
            head->flag=true;
        }
        int m=0;
        int anssize=INT_MAX;
        int op;
        for(string s:wordsContainer)
        {
            if(s.size()<anssize)
            {
                anssize=s.size();
                op=m;
            }
            m++;
        }
        int ans=op;
        vector<int>x;
        for(int i=0;i<wordsQuery.size();i++)
        {
            head=root;
            for(int j=wordsQuery[i].size()-1;j>=0;j--)
            {
                char c=wordsQuery[i][j];
                if(head->child[c-'a']==NULL)
                {
                   anssize=INT_MAX;
                   ans=op;
                   for(int k=0;k<head->ind.size();k++)
                    {
                        if(wordsContainer[head->ind[k]].size()<anssize)
                        {
                            anssize=wordsContainer[head->ind[k]].size();
                            ans=head->ind[k];
                        }
                    }
                    x.push_back(ans);
                    goto cc;
                }
                head=head->child[c-'a'];
            }
            anssize=INT_MAX;
            for(int k=0;k<head->ind.size();k++)
                    {
                        if(wordsContainer[head->ind[k]].size()<anssize)
                        {
                            anssize=wordsContainer[head->ind[k]].size();
                            ans=head->ind[k];
                        }
                    }
                    x.push_back(ans);
            cc:
        }
        return x;
    }
};
