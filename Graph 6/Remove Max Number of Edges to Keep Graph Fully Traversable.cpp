class Solution {
public:
    class DisjointSet {
        public:
        vector<int>parent;
        vector<int>size;
        DisjointSet(int n)
        {
            size.resize(n,1);
            parent.resize(n);
            for(int i=0;i<n;i++)
            {
                parent[i] = i;
            }
        }
        int find(int u)
        {
            if(parent[u]==u) return u;
            return parent[u]=find(parent[u]);
        }
        void uni(int u,int v)
        {
            u=find(u);
            v=find(v);
            if(u==v) return;
            if(size[u]<size[v])
            {
                parent[u]=v;
                size[v]+=size[u];
            }
            else
            {
                parent[v]=u;
                size[u]+=size[v];
            }
        }
    };
    int addedges(DisjointSet ds,vector<pair<int,int>>& edges){
        int used=0;
        for(auto i:edges)
        {
            if(ds.find(i.first)!=ds.find(i.second))
            {
                ds.uni(i.first,i.second);
                used++;
            }
        }
        return used;
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<pair<int,int>>edg[4];
        for(auto i:edges)
        {
            edg[i[0]].push_back({i[1],i[2]});
        }
        DisjointSet ds(n+1);
        int used=0;
        for(auto i:edg[3])
        {
            if(ds.find(i.first)!=ds.find(i.second))
            {
                ds.uni(i.first,i.second);
                used++;
            }
        }
        if(used==n-1) return edges.size()-used;
        int used2=addedges(ds,edg[2])+addedges(ds,edg[1]);
        if(2*used+used2!=2*(n-1)) return -1;
        else return edges.size()-(used + used2);
    }
};
