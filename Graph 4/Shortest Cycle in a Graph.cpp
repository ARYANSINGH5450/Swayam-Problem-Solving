class Solution {
public:
    int ans=INT_MAX;
    void bfs(int node,vector<int>adj[],int n){
        vector<int>dist(n,-1);
        dist[node]=0;
        queue<int>q;
        q.push(node);
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            for(auto v:adj[u]){
                if(dist[v]==-1)
                {
                    dist[v]=dist[u]+1;
                    q.push(v);
                }
                else if(dist[v]>=dist[u])
                {
                    ans=min(ans,dist[u]+dist[v]+1);
                }
            }
        }
    }
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        for(auto i:edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        for(int i=0;i<n;i++)
        {
            bfs(i,adj,n);
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};
