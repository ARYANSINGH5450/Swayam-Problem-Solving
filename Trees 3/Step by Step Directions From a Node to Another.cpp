class Solution {
public:
    bool path(TreeNode *root,int node,string &curr,string &ans)
    {
        if(!root)
        {
            return false;
        }
        if(root->val==node)
        {
            ans=curr;
            return true;
        }
        curr.push_back('L');
        if(path(root->left,node,curr,ans))
        {
            return true;
        }
        curr.pop_back();
        curr.push_back('R');
        if(path(root->right,node,curr,ans))
        {
            return true;
        }
        curr.pop_back();
        return false;
    }
    string getDirections(TreeNode* root,int startValue,int destValue) 
    {
        if(!root||startValue==destValue) 
        {
            return " ";
        }
        string l=" ",r=" ",curr=" ";
        path(root,startValue,curr,l);
        curr=" ";
        path(root,destValue,curr,r);
        int i=0,j=0;
        while(i<l.size()&&j<r.size()&&l[i]==r[j])
        {
            i++;
            j++;
        }
        l=l.substr(i);
        for(int i=0;i<l.length();i++)
        {
            l[i]='U';
        }
        return l+r.substr(j);
    }
};
