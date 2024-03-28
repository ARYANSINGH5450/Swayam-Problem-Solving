class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL)
        {
            return {};
        }
        queue<TreeNode*>q;
        q.push(root);
        vector<int>res;
        while(!q.empty()) 
        {
            int count=q.size();
            for(int i=count;i>0;i--) 
            {
                TreeNode* node=q.front();
                q.pop(); 
                if(i==count) 
                {
                    res.push_back(node->val);
                }                
                if(node->right!=NULL) 
                {
                    q.push(node->right);
                }
                if(node->left!=NULL) 
                {
                    q.push(node->left);
                }
            }
        }
        return res;
    }
};
