class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)
        {
            return ans;
        }
        queue<TreeNode *>q;
        q.push(root);
        int cnt=0;
        TreeNode* curr;
        vector<int>temp;
        while(!q.empty())
        {
            cnt=q.size();
            temp.clear();
            for(int i=0;i<cnt;i++)
            {
                curr=q.front();
                q.pop();
                temp.push_back(curr->val);
                if(curr->left!=NULL)
                q.push(curr->left);
                if(curr->right!=NULL)
                q.push(curr->right);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
