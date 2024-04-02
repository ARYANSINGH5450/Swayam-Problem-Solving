int findCeil(Node* root, int input) {
    int ans=-1;
    while(root)
    {
    if(root->data==input)
    {
        return input;
    }
    if(root->data>input)
    {
        ans=root->data;
        root=root->left;
    }
    else
    {
        root=root->right;
    }
    }
return ans;
}
