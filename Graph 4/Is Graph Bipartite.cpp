class Solution {
public:
    bool dfs(queue<int>& q,vector<int>& color,vector<int>& vis,vector<vector<int>>graph)
    {
        while(!q.empty())
        {
            int temp=q.front();
            q.pop();
            vis[temp]=1;
            for(auto i:graph[temp])
            {
                if(!vis[i])
                {
                    q.push(i);
                    color[i]=!color[temp];
                }
                else if(color[i]==color[temp])
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        queue<int>q;
        vector<int>color(graph.size());
        vector<int>vis(graph.size(),0);
        for(int i=0;i<graph.size();i++)
        {
            if(!vis[i])
            {
                q.push(i);
                color[i]=0;
                if(dfs(q,color,vis,graph)==false) return false;
            }
        }
        return true;
    }
};
