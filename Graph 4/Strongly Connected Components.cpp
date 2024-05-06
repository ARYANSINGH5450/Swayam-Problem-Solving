class Solution
{
	public:
	void dfs(int i,vector<int>& vis,stack<int>& s,vector<vector<int>>& adj)
	{
	    vis[i]=1;
	    for(auto j:adj[i])
	    {
	        if(!vis[j]) dfs(j,vis,s,adj);
	    }
	    s.push(i);
	}
	void dfsn(int i,vector<int>& vis,vector<vector<int>>& adjn)
	{
	    vis[i]=1;
	    for(auto j:adjn[i])
	    {
	        if(!vis[j]) dfsn(j,vis,adjn);
	    }
	}
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        stack<int>s;
        vector<int>vis(adj.size(),0);
        for(int i=0;i<adj.size();i++)
        {
            if(!vis[i])
            {
                dfs(i,vis,s,adj);
            }
        }
        for(int i=0;i<V;i++)
        {
            vis[i]=0;
        }
        vector<vector<int>>adjn(V);
        for(int i=0;i<adj.size();i++)
        {
            for(int j=0;j<adj[i].size();j++)
            {
                adjn[adj[i][j]].push_back(i);
            }
        }
        int c=0;
        while(!s.empty())
        {
            int n=s.top();
            s.pop();
            if(!vis[n])
            {
                c++;
                dfsn(n,vis,adjn);
            }
        }
        return c;
    }
};
