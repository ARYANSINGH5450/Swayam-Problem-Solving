class Solution {
public:
    TreeNode* f(vector<int>& v,int& i,int high)
    {
        if(i==v.size()||v[i]>high)
        {
            return NULL;
        }
        TreeNode* node=new TreeNode(v[i++]);
        node->left=f(v,i,node->val);
        node->right=f(v,i,high);
        return node; 
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return f(preorder,i,INT_MAX);
    }
};
