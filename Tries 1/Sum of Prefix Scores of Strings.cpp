class Solution {
public:
    struct trie{
        trie* child[26];
        bool flag;
        int cp;
        trie()
        {
            for(int i=0;i<26;i++)
            {
                child[i]=nullptr;
            }
            flag=false;
            cp=0;
        }
    };
    trie* root=new trie();
    vector<int> sumPrefixScores(vector<string>& words) {
        trie* head;
        for(int i=0;i<words.size();i++)
        {
            head=root;
            for(int j=0;j<words[i].size();j++)
            {
                char c=words[i][j];
                if(head->child[c-'a']==NULL)
                {
                    head->child[c-'a']=new trie();
                }
                head->child[c-'a']->cp++;
                head=head->child[c-'a'];
            }
            head->flag=true;
        }
        vector<int>v;
        for(int i=0;i<words.size();i++)
        {
            head=root;
            int s=0;
            for(int j=0;j<words[i].size();j++)
            {
                char c=words[i][j];
                s+=head->child[c-'a']->cp;
                head=head->child[c-'a'];
            }
            v.push_back(s);
        }
        return v;
    }
};
