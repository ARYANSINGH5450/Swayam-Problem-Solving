class Solution {
public:
    void dfs(vector<int>& vis,vector<int>adj[],int i,int& count)
    {
        vis[i]=1;
        count++;
        for(auto j:adj[i])
        {
            if(vis[j]==0)
            {
                dfs(vis,adj,j,count);
            }
        }  
    }
    int minSwapsCouples(vector<int>& row) {
        for(auto& i:row)
        {
            i=i/2;
        }
        int n=row.size();
        vector<int>adj[n];
        for(int i=0;i<n;i+=2)
        {
            if(row[i]==row[i+1]) continue;
            else
            {
                adj[row[i]].push_back(row[i+1]);
                adj[row[i+1]].push_back(row[i]);
            }
        }
        vector<int>vis(n,0);
        int sum=0;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                int count=0;
                dfs(vis,adj,i,count);
                sum+=(count-1);
            }
        }
        return sum;
    }
};
