class Solution
{
  public:
    Node* add(Node* left,Node* right){
    if(right==NULL)
    {
        return left;
    }
    if(left==NULL)
    {
        return right;
    }
    Node* lt;
    Node* rt;
    lt=left->left;
    rt=right->left;
    lt->right=right;
    right->left=lt;
    left->left=rt;
    rt->right=left;
    return left;
}
Node *bTreeToCList(Node *root)
{
    if(root==NULL)
    {
        return NULL;
    }
    Node* left;
    Node* right;
    left=bTreeToCList(root->left);
    right=bTreeToCList(root->right);
    root->left=root;
    root->right=root;
    return add(add(left,root),right);
}
};
