void f(Node *root,int l,vector<int>&res)
    {
       if (root==NULL)
       {
           return;
       }
        if (res.size()==l)
        {
          res.push_back(root->data);
        }
        f(root->left,l+1,res);
        f(root->right,l+1,res);
    }
vector<int> leftView(Node *root)
{
        vector<int>res;
        f(root,0,res);
        return res;
}
