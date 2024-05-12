class DisjointSet{
  public:
  vector<int>parent;
  vector<int>size;
  DisjointSet(int n)
  {
      parent.resize(n+1);
      size.resize(n+1);
      for(int i=0;i<n;i++)
      {
          parent[i]=i;
          size[i]=1;
      }
  }
  int Parent(int node)
  {
      if(node==parent[node]) return node;
      return parent[node]=Parent(parent[node]);    
  }
  void uni(int u,int v)
  {
      int ulpu=Parent(u);
      int ulpv=Parent(v);
      if(ulpu==ulpv) return;
      if(size[ulpu]<size[ulpv])
      {
          parent[ulpu]=ulpv;
          size[ulpv]+=size[ulpu];
      }
      else
      {
          parent[ulpv]=ulpu;
          size[ulpu]+=size[ulpv];
      }
  }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int>ans;
        DisjointSet ds(edges.size());
        for(auto i:edges)
        {
            int u=i[0];
            int v=i[1];
            if(ds.Parent(u)==ds.Parent(v)) return {u,v};
            else
            {
                ds.uni(u,v);
            }
            ds.uni(u,v);
        }
        return {};
    }
};
