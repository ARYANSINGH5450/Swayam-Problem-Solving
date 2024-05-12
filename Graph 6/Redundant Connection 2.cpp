class Solution{
public:
    int findpar(int node,vector<int>& parent)
    {
        if(node==parent[node]) return node;
        return parent[node]=findpar(parent[node],parent);
    }
    bool uni(int u,int v,vector<int>& rank,vector<int>& parent)
    {
        u=findpar(u,parent);
        v=findpar(v,parent);
        if(u==v)
        {
            return true;
        }
        if(rank[u]<rank[v])
        {
            parent[u]=v;
        }
        else if(rank[u]>rank[v])
        {
            parent[v]=u;
        }
        else
        {
            parent[u]=v;
            rank[v]++;  
        }
        return false;
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
       int n=edges.size();
       int first=-1,second=-1;
       vector<int>parent(n+1);
       vector<int>rank(n+1,0);
       vector<int>indegree(n+1,-1);
       for(int i=0;i<n;i++)
       {
           parent[i]=i;
       }
       for(int i=0;i<n;i++)
      {
           int u=edges[i][0];
           int v=edges[i][1];
           if(indegree[v]!=-1)
           {
               first=i;
               second=indegree[v];
               break;
           }
           else
           {
               indegree[v]=i;
           }
       }
       for(int i=0;i<n;i++)
       {
            if(i==first) continue;
            if(uni(edges[i][0],edges[i][1],rank,parent))
            {
                if(first==-1)
                {
                    return edges[i];
                }
                else
                {
                    return edges[second];
                }
            }
        }
        return edges[first];
     }
};
