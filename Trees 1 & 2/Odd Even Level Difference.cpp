int function(Node* root)
{
    if(root==NULL) return 0;
    queue<Node*>q;
    q.push(root);
    int l=0,os=0,es=0;
    while (!q.empty()) 
    {
        int n=q.size();
        l+=1;
        while(n>0)
        {
            Node* temp=q.front();
            q.pop();
            if(l%2 == 0)
                es+=temp->data;
            else
                os+=temp->data;
            if (temp->left) 
            {
                q.push(temp->left);
            }
            if(temp->right)
            {
                q.push(temp->right);
            }
            n-=1;
        } 
    }
    return (os-es);
}
