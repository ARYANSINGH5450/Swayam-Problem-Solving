class Solution {
  public:
    vector<int>topView(Node *root) {
        if(root == NULL)
        {
            return {}; 
        }
        map<int,int>m; 
        vector<int>ans;
        queue<pair<Node*,int>>q; 
        q.push({root, 0}); 
        while(!q.empty()) 
        {
            auto i=q.front(); 
            q.pop(); 
            Node* n=i.first; 
            int l=i.second;
            if(m.find(l)==m.end())
            {
              m[l]=n->data;
            }
            if(n->left!=NULL) 
            {
                q.push({n->left,l-1}); 
            }
            if(n->right!=NULL)
            {
                q.push({n->right,l+1}); 
            }  
        }
        for(auto i:m) 
        {
            ans.push_back(i.second); 
        }
        return ans;  
    }
};
