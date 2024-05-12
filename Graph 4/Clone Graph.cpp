class Solution {
public:
    map<Node*,Node*>m;
    void dfs(Node* node)
    {
        Node* temp=new Node(node->val);
        m[node]=temp;
        for(auto i:node->neighbors)
        {
            if(m.find(i)!=m.end())
            {
                temp->neighbors.push_back(m[i]);
            }
            else
            {
                dfs(i);
                temp->neighbors.push_back(m[i]);
            }
        }
    }
    
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        dfs(node);
        return m[node];
    }
};
