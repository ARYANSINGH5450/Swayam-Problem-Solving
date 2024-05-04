class Solution {
public:
    void dfs(vector<int>adj[],queue<int>& q,vector<set<int>>& ans,vector<int>& ind)
    {
        while(!q.empty())
        {
            int temp=q.front();
            q.pop();
            for(int i=0;i<adj[temp].size();i++)
            {
               for(auto l:ans[temp])
               { 
                   ans[adj[temp][i]].insert(l);
               }
                ans[adj[temp][i]].insert(temp);
                ind[adj[temp][i]]--;
                if(ind[adj[temp][i]]==0)
                {
                    q.push(adj[temp][i]);
                }
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        vector<int>ind(n,0);
        vector<set<int>>ans(n);
        queue<int>q;
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            ind[edges[i][1]]++;
        }
        for(int i=0;i<n;i++)
        {
               if(ind[i]==0)
               {
                   q.push(i);
               }
        }
        dfs(adj,q,ans,ind);
        vector<vector<int>>f;
        for(auto t:ans)
        {
            vector<int>vt(t.begin(),t.end());
            f.push_back(vt);
            
        }
        return f;
    }
};
