class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        vector<int>adj[colors.size()];
        vector<vector<int>>a(colors.size(),vector<int>(26,0));
        vector<int>ind(colors.size(),0);
        int ans=1;
        int c=0;
        queue<int>q;
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            ind[edges[i][1]]++;
        }
        for(int i=0;i<colors.size();i++)
        {
            if(!ind[i])
            {
                q.push(i);
                a[i][colors[i]-'a']=1;
            }
        }
         while(!q.empty())
        {
            int temp=q.front();
            q.pop();
            c++;
            for(int i=0;i<adj[temp].size();i++)
            {
                for(int j=0;j<26;j++)
                {
                    a[adj[temp][i]][j]=max(a[adj[temp][i]][j],a[temp][j]+(j==colors[adj[temp][i]]-'a'));
                    ans=max(ans,a[adj[temp][i]][j]);
                }
                ind[adj[temp][i]]--;
                if(ind[adj[temp][i]]==0)
                {
                    q.push(adj[temp][i]);
                }
            }
        }
        if(c==colors.size()) return ans;
        return -1;
    }
};
