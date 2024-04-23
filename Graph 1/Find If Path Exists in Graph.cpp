class Solution {
public:
    bool bfs(queue<int>q,int destination,vector<int>vis,vector<int>adj[])
    {
        while(!q.empty()){
        if(!vis[q.front()])
        {
            vis[q.front()]=1;
            for(auto i:adj[q.front()])
            {
                if(i==destination)
                {
                    return true;
                }
                q.push(i);
            }
        }
        q.pop();
    }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source==destination)
        {
            return true;
        }
        vector<int>vis(n,0);
        queue<int>q;
        vector<int>adj[n];
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        q.push(source);
        return bfs(q,destination,vis,adj);
    }
};
