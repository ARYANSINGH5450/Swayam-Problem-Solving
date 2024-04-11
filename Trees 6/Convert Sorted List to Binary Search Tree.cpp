class Solution {
public:
    TreeNode* f(vector<int>& v,int l,int h)
    {
        if(l>h)
        {
            return NULL;
        }
        int mid=(l+h)/2;
        TreeNode* root=new TreeNode(v[mid]);
        root->left=f(v,l,mid-1);
        root->right=f(v,mid+1,h);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>v;
        while(head!=NULL)
        {
            v.push_back(head->val);
            head=head->next;
        }
        return f(v,0,v.size()-1);
    }
};
