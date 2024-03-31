class Solution {
public:
    void f(TreeNode* &root,int target,int sum,bool& ans){
        if(root==NULL)
        {
            return;
        }
        if(root->left==NULL&&root->right==NULL)
        {
            sum+=root->val;
            if(sum==target)
            {
                ans=true;
            }
            sum-=root->val;
            return;
        }
        sum+=root->val;
        f(root->left,target,sum,ans);
        f(root->right,target,sum,ans);
        sum-=root->val;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
     int sum=0;
     bool ans=false;
     f(root,targetSum,sum,ans);
     return ans;
    }
};
