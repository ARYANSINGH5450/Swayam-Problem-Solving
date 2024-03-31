class Solution {
public:
    int height(TreeNode* root)
    {
        if(!root)return 0;
        return max(height(root->left),height(root->right))+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }
        int h=height(root->right)+height(root->left);
        int ld=diameterOfBinaryTree(root->left);
        int rd=diameterOfBinaryTree(root->right);
        return max(h,max(ld,rd));   
    }
};
