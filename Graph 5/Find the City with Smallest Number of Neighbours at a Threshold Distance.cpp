class Solution {
public:
    vector<int>f(vector<pair<int,int>>adj[],int src,int n)
    {
        vector<int>dis(n,INT_MAX);
        dis[src]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,src});
        while(!pq.empty())
        {
            int dist=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto i:adj[node])
            {
                int n=i.first;
                int dt=i.second;
                if(dis[n]>dist+dt)
                {
                    dis[n]=dis[node]+dt;
                    pq.push({dis[n],n});
                }
            }
        }
        return dis;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) 
    {
        vector<pair<int,int>>adj[n];
        for(auto i:edges)
        {
            vector<int>temp=i;
            int u=temp[0];
            int v=temp[1];
            int wt=temp[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        int res=INT_MAX;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            vector<int>dis=f(adj,i,n);
            int cnt=0;
            for(auto i:dis)
            {
                if(i<=distanceThreshold) cnt++;
            }
            if(cnt<=res)
            {
                res=cnt;
                ans=i;
            }    
        }
        return ans;
	}
};
