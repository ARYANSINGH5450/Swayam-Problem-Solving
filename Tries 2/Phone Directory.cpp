class Solution{
public:
struct trie
{
    trie* child[26];
    vector<int>index;
    trie()
    {
        for(int i=0;i<26;i++)
        {
            child[i]=nullptr;
        }
    }
};
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        trie* root=new trie();
        trie* head=root;
        sort(contact,contact+n);
        for(int i=0;i<n;i++)
        {
            head=root;
            for(int j=0;j<contact[i].size();j++)
            {
                char c=contact[i][j];
                if(!head->child[c-'a'])
                {
                    head->child[c-'a']=new trie();
                }
                head->child[c-'a']->index.push_back(i);
                head=head->child[c-'a'];
            }
        }
        head=root;
        vector<string>v;
        vector<vector<string>>ans;
        for(int i=0;i<s.size();i++)
        {
            char c=s[i];
            if(head->child[c-'a'])
            {
                for(int j=0;j<head->child[c-'a']->index.size();j++)
                {
                    v.push_back(contact[head->child[c-'a']->index[j]]);
                }
            }
            else
            {
                for(int k=i;k<s.size();k++)
                {
                    ans.push_back({"0"});
                }
                return ans;
            }
            set<string>se(v.begin(),v.end());
            vector<string>x(se.begin(),se.end());
            ans.push_back(x);
            v.clear();
            head=head->child[c-'a'];
        }
        return ans;
    }
};
