class Solution {
    public:
    TreeNode* prev;
    TreeNode* first;
    TreeNode* last;
    void inorder(TreeNode* root)
    {
        if(root==NULL)
        {
            return;
        }
        inorder(root->left);
        if(prev!=NULL&&root->val<prev->val)
        {
            if(first==NULL)
            {
                first=prev;
                last=root;
            }
            else
            {
                last=root;
            }
        }
        prev=root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        first=NULL;
        last=NULL;
        prev=new TreeNode(INT_MIN);
        inorder(root);
        swap(first->val,last->val);
    }
};
