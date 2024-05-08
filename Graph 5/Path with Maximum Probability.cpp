class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        priority_queue<pair<double,int>>pq;
        vector<int>vis(n,0);
        vector<vector<pair<int,double>>>adj(n);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        vector<double>prob(n,0);
        prob[start]=1;
        pq.push({1,start});
        while(!pq.empty())
        {
            pair<double,int>p = pq.top();
            pq.pop();
            for(auto i:adj[p.second])
            {
                   if(!vis[i.first])
                   {
                       if(prob[i.first]<prob[p.second]*i.second)
                       {
                           prob[i.first]=prob[p.second]*i.second;
                           pq.push({prob[i.first],i.first});
                       }
                   }
               
            }
            vis[p.second]=1;
        }
        return prob[end];
    }
};
