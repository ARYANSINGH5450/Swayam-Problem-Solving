class Solution {
public:
    void dfs(vector<int>adj[],queue<int>q,vector<int>& vis)
    {
        while(!q.empty())
        {
            if(!vis[q.front()]){
            vis[q.front()]=1;
            for(auto it:adj[q.front()])
            {
                q.push(it);
            }
            }
            q.pop();
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int>adj[isConnected.size()];
        vector<int>vis(isConnected.size(),0);
        queue<int>q;
        int ans=0;
        for(int i=0;i<isConnected.size();i++)
        {
            for(int j=0;j<isConnected.size();j++)
            {
                if(isConnected[i][j]==1) adj[i].push_back(j);
            }
        }
        for(int i=0;i<isConnected.size();i++)
        {
            if(!vis[i])
            {
                ans++;
                q.push(i);
                dfs(adj,q,vis);
            }
        }
        return ans;
    }
};
