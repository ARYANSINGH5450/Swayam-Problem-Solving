class Solution{
    public:
int fl(Node *root,int m,int level) {
    if (root==NULL) 
    {
      return -1;
    }
    if (root->data==m)
    {
      return level;
    }
    int l=fl(root->left,m,level + 1);
  if(l==-1)
  {
    return fl(root->right,m,level+1);
  }
  return l;
}

Node *d(Node *root,int a,int b,int &d1,int &d2,int &dist,int level) {
    if (root==NULL) 
    {
      return NULL;
    }
    if (root->data==a) 
    {
        d1=level;
        return root;
    }
    if (root->data==b) 
    {
        d2=level;
        return root;
    }
    Node *l=d(root->left,a,b,d1,d2,dist,level+1);
    Node *r=d(root->right,a,b,d1,d2,dist,level+1);
    if (l!=NULL&&r!=NULL) 
    {
        dist=d1+d2-level*2;
    }
    if(l!=NULL)
    {
        return l;
    }
    return r;
}
int findDist(Node *root, int a, int b) {
    int d1=-1,d2=-1,dist;
    Node *lca=d(root,a,b,d1,d2,dist,1);
    if (d1!=-1&&d2!=-1) 
    {
        return dist;
    }
    if (d1!=-1)
    {
        return fl(lca, b, 0);
    }
    if (d2!=-1) 
    {
        return fl(lca,a,0);
    }
    return -1;
}
};
