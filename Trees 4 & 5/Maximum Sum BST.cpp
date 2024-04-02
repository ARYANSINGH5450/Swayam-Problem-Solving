class Solution {
    public:
    struct info{
       int maxi;
       int mini;
       bool isbst;
       int size;
    };
info f(TreeNode* root,int& res)
{
    if(root==NULL)
    {
        return {INT_MIN,INT_MAX,true,0};
    }
info left=f(root->left,res);
info right=f(root->right,res);
info node;
node.size=left.size+right.size+root->val;
node.maxi=max(root->val,right.maxi);
node.mini=min(root->val,left.mini); 
if(left.isbst&&right.isbst&&(root->val>left.maxi&&root->val<right.mini))
{
    node.isbst=true;
}
else
{
    node.isbst=false;
}
if(node.isbst)
{
    res=max(res,node.size);
}
 return node;
}
    int maxSumBST(TreeNode* root) {
        int ms=0;
        f(root,ms);
    return ms;
    }
};
