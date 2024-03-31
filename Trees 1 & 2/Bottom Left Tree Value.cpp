class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);

        int res=0;
        while(q.size())
        {
            int sz = q.size();
            res = q.front()->val;
            while(sz--)
            {
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }
        return res;
    }
};
