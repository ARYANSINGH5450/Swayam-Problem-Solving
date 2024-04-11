class Solution
{
    public:
    void inorder(Node* root,vector<int>& v)
    {
        if(root==NULL)
        {
            return;
        }
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }
    vector<int> merge(Node *root1, Node *root2)
    {
        vector<int>v;
        inorder(root1,v);
        inorder(root2,v);
        sort(v.begin(),v.end());
        return v;
    }
};
