class Solution {
public:
    void f(TreeNode* root,int target,int sum ,vector<vector<int>>&ans,vector<int>&path)
    {
        if(root==NULL)
        {
            return;
        }
        if(root->left==NULL&&root->right==NULL)
        {
            path.push_back(root->val);
            sum+=root->val;
            if(sum==target)
            {
                ans.push_back(path);
            }
            sum-=root->val;
            path.pop_back();
        }
        path.push_back(root->val);
        sum+=root->val;
        f(root->left,target,sum,ans,path);
        f(root->right,target,sum,ans,path);
        path.pop_back();
        sum-=root->val;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>v;
        int sum=0;
        f(root,targetSum,sum,ans,v);
        return ans;
    }
};
