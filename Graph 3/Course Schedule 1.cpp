class Solution {
public:
    bool f(int i,vector<int>& vis,vector<int>& pvis,vector<int>adj[])
    {
        vis[i]=1;
        pvis[i]=1;
        for(auto j:adj[i])
        {
            if(!vis[j])
            {
                if(f(j,vis,pvis,adj))
                {
                    return true;
                }
            }
            else if(pvis[j]==1)
            {
                return true;
            }
        }
        pvis[i]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int V=numCourses;
        vector<int>adj[V];
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int>vis(V,0);
        vector<int>pvis(V,0);
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                if(f(i,vis,pvis,adj))
                {
                    return false;
                }
            }
        }
        return true;
    }
};
