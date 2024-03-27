class Solution {
public:
    map<int,vector<int>> mp;
    unordered_map<int,int>rmap;
    void pre(TreeNode* root,int col,int row)
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
                    else if(rmap[mp[col][i]]==row and mp[col][i]>root->val)
                    {
                        mp[col].insert(mp[col].begin()+i,root->val);
                        f=1;
                        break;
                    }
                }
                if(!f) mp[col].push_back(root->val);
            }
            pre(root->left,col-1,row+1);
            pre(root->right,col+1,row+1);
        }
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        pre(root,0,0);
        vector<vector<int>> res;
        for(auto it:mp)
        {
             res.push_back(it.second);
        } 
        return res;
    }
};
