class Solution {
public:
    map<int,vector<int>>mp;
    unordered_map<int,int>rmap;
    void fun(TreeNode* root,int col,int row)
    {
        if(root)
        {
            rmap[root->val]=row;
            if(mp[col].size()==0)
            {
            mp[col].push_back(root->val);
            }
            else
            {
                bool f=0;
                for(int i=0;i<mp[col].size();i++)
                {
                    if(rmap[mp[col][i]]>row)
                    {
                        mp[col].insert(mp[col].begin()+i,root->val);
                        f=1;
                        break;
                    }
                    else if(rmap[mp[col][i]]==row&&mp[col][i]>root->val)
                    {
                        mp[col].insert(mp[col].begin()+i,root->val);
                        f=1;
                        break;
                    }
                }
                if(!f)
                {
                    mp[col].push_back(root->val);
                }
            }
            fun(root->left,col-1,row+1);
            fun(root->right,col+1,row+1);
        }
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        fun(root,0,0);
        vector<vector<int>> res;
        for(auto i:mp)
        {
             res.push_back(i.second);
        } 
        return res;
    }
};
