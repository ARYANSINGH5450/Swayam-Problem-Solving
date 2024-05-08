class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        vector<pair<int,int>>adj[n];
        vector<int>vis(n,0);
        for(auto i:edges){
            adj[i[0]].push_back({i[1],i[2]});
            adj[i[1]].push_back({i[0],i[2]});
        }
        vector<int>dist(n,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        dist[0]=0;
        vector<int>ans(n);
        while(!pq.empty())
        {
            int d=pq.top().first;
            int x=pq.top().second;
            pq.pop();
            if(d>=disappear[x])
            {
                vis[x]=1;
                continue;
            } 
           if(vis[x]==1) 
           {
                continue;
           }
           vis[x]=1;
           for(auto i:adj[x])
           {
                if(vis[i.first]==1) continue;
                if((dist[x]+i.second<=dist[i.first])&&dist[x]+i.second<disappear[i.first])
                {
                    dist[i.first]=dist[x]+i.second;
                    pq.push({dist[i.first],i.first});
                }   
            }        
        }
        for(int i=0;i<n;i++)
        {
            if(dist[i]>=disappear[i])
            {
                dist[i]=-1;
            }
        }
        return dist;
    }
};
