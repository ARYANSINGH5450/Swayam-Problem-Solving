class Solution {
public:
    int ans;
    void inorder(TreeNode* root,int k,int& c)
    {
        if(root==NULL)
        {
            return;
        }
        inorder(root->left,k,c);
        c++;
        if(c==k)
        {
            ans=root->val;
            return;
        }
        inorder(root->right,k,c);
    }
    int kthSmallest(TreeNode* root, int k) {
        int c=0;
        inorder(root,k,c);
        return ans;
     }
};
