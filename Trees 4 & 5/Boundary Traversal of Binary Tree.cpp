class node{
    public:
    int ma,mi,s;
    node(int mini,int maxi,int size)
    {
        this->mi=mini;
        this->ma=maxi;
        this->s=size;
    }
};
class Solution{
    public:
    node lbst(Node* root)
    {
        if(root==NULL)
        {
            return node(INT_MAX,INT_MIN,0);
        }
        node left=lbst(root->left);
        node right=lbst(root->right);
        if(left.ma<root->data&&root->data<right.mi)
        {
            return node(min(root->data,left.mi),max(root->data,right.ma),left.ma+right.ma+1);
        }
        return node(INT_MIN,INT_MAX,max(left.ma,right.ma));
    }
    int largestBst(Node *root)
    {
    	return lbst(root).ma;
    }
};
