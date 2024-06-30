class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        queue<pair<pair<int,int>,int>>q;
        q.push({{0,src},0});
        vector<int>dis(n,1e9);
        dis[src]=0;
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<flights.size();i++)
        {
            adj[flights[i][0]].push_back({flights[i][2],flights[i][1]});
        }
        while(!q.empty())
        {
            int node=q.front().first.second;
            int price=q.front().first.first;
            int stops=q.front().second;
            q.pop();
            for(auto it:adj[node])
            {
                if((price+it.first)<dis[it.second]&&stops<=k)
                {
                    dis[it.second]=price+it.first;
                    q.push({{dis[it.second],it.second},stops+1});
                }
            }
        }
        if(dis[dst]==1e9)
        {
            return -1;
        }
        return dis[dst];
    }
};
