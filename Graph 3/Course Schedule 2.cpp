class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
       vector<int>adj[numCourses];
        queue<int>q;
        vector<int>v;
        vector<int>ind(numCourses,0);
       for(int i=0;i<prerequisites.size();i++)
       {
           adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
       }
        for(int i=0;i<numCourses;i++)
        {
            for(int j=0;j<adj[i].size();j++)
            {
                ind[adj[i][j]]++;
            }
        }
        for(int i=0;i<ind.size();i++)
        {
            if(ind[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty())
        {
            for(int i=0;i<adj[q.front()].size();i++)
            {
                ind[adj[q.front()][i]]--;
                if(ind[adj[q.front()][i]]==0)
                {
                    q.push(adj[q.front()][i]);
                }
            }
            v.push_back(q.front());
            q.pop();
        }
        if(v.size()!=numCourses) v.clear();
        return v;
    }
};
