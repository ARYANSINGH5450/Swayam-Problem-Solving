class Solution {
public:
    void f(TreeNode *root,int l,vector<int>&res)
    {
       if (root==NULL)
       {
           return;
       }
        if (res.size()==l)
        {
          res.push_back(root->val);
        }
        f(root->right,l+1,res);
        f(root->left,l+1,res);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        f(root,0,res);
        return res;
     } 
};
