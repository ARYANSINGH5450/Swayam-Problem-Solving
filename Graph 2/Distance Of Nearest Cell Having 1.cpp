class Solution 
{
    public:
    void f(vector<vector<int>>& grid,vector<vector<int>>& res,vector<vector<int>>& vis,queue<pair<pair<int,int>,int>>& q)
    {
        while(!q.empty())
        {
            int i=q.front().first.first;
            int j=q.front().first.second;
            int d=q.front().second;
            res[i][j]=d;
            if(i+1<grid.size()&&vis[i+1][j]==0)
            {
                q.push({{i+1,j},d+1});
                vis[i+1][j]=1;
            }
            if(i-1>=0&&vis[i-1][j]==0)
            {
                q.push({{i-1,j},d+1});
                vis[i-1][j]=1;
            }
            if(j-1>=0&&vis[i][j-1]==0)
            {
                q.push({{i,j-1},d+1}); 
                vis[i][j-1]=1;
            }
            if(j+1<grid[0].size()&&vis[i][j+1]==0)
            {
               q.push({{i,j+1},d+1}); 
               vis[i][j+1]=1;
            }
            q.pop();
        }
    }
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
	    vector<vector<int>>res(grid.size(),vector<int>(grid[0].size(),0));
	    queue<pair<pair<int,int>,int>>q;
	    for(int i=0;i<grid.size();i++)
	    {
	        for(int j=0;j<grid[0].size();j++)
	        {
	            if(grid[i][j]==1)
	            {
	                q.push({{i,j},0});
	                res[i][j]=0;
	                vis[i][j]=1;
	            }
	        }
	    }
	    f(grid,res,vis,q);
	    return res; 
	    
	}
};
