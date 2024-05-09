class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int dis=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                adj[i].push_back({j,dis});
                adj[j].push_back({i,dis});
            }
        }
        vector<int>vis(n,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,0});
        int sum=0;
        while(!pq.empty())
        {
            auto i=pq.top();
            pq.pop();
            if(vis[i.second])
            {
                continue;
            }
            vis[i.second]=1;
            sum+=i.first;
            for(auto j:adj[i.second])
            {
                pq.push({j.second,j.first});
            }
        }
        return sum;
    }
};
