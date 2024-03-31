class Codec {
public:
    string serialize(TreeNode* root) {
        if(root==NULL) 
        {
            return ""; 
        }
        string s ="";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()) 
        {
           TreeNode* n=q.front();
           q.pop();
           if(n==NULL)
           {
               s.append("#,");
           }
           else 
           {
               s.append(to_string(n->val)+',');
           }
           if(n!=NULL)
           {
               q.push(n->left);
               q.push(n->right);            
           }
        }
        return s;
    }
    TreeNode* deserialize(string data)
    {
        if(data.size()==0)
        {
            return NULL; 
        }
        stringstream s(data);
        string str; 
        getline(s,str,',');
        TreeNode *root=new TreeNode(stoi(str));
        queue<TreeNode*>q; 
        q.push(root); 
        while(!q.empty()) 
        {
            TreeNode *node=q.front(); 
            q.pop();  
            getline(s,str,',');
            if(str=="#") 
            {
                node->left=NULL; 
            }
            else 
            {
                TreeNode* ln=new TreeNode(stoi(str)); 
                node->left=ln; 
                q.push(ln); 
            }
            getline(s,str,',');
            if(str=="#") 
            {
                node->right=NULL; 
            }
            else 
            {
                TreeNode* rn=new TreeNode(stoi(str)); 
                node->right=rn;
                q.push(rn); 
            }
        }
        return root; 
    }
};
