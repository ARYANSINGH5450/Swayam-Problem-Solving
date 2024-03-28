class Solution {
public:
int c=0;
long long sum=0;
    void f(TreeNode* &root,int &target)
    {
            if(root==NULL)
            {
                return;
            }
            sum+=root->val;
            if(sum==target)
            {
                c++;
            }
        f(root->left,target);
        f(root->right,target);
        sum-=root->val;

    }
    int pathSum(TreeNode* &root, int &targetSum) {
        if(root==NULL)
        {
            return 0;
        }
        f(root,targetSum);
        pathSum(root->left,targetSum);
        pathSum(root->right,targetSum);
        return c;
    }
};
