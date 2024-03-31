class Solution {
public:
    int maxDepth(TreeNode* root) {
    if(root==NULL) return 0;
    queue<TreeNode*>q;
    q.push(root);
    q.push(NULL);
    int count=0;
    while(!q.empty())
    {
        if(q.front()==NULL)
        {
            count++;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else
        {
            TreeNode* temp=q.front();
            if(temp->left!=NULL)
            {
                q.push(temp->left);
            }
            if(temp->right!=NULL)
            {
                q.push(temp->right);
            }
            q.pop();
        }
    }
   return count;
    }
};
