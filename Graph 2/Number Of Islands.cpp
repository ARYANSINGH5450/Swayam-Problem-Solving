class Solution {
public:
    void f(int i,int j,vector<vector<char>>& grid,vector<vector<int>>& vis)
    {
        if(i<0||i>=grid.size()||j<0||j>=grid[0].size()||vis[i][j]==1)
        {
            return;
        }
        if(grid[i][j]=='0')
        {
            return;
        }
        vis[i][j]=1;
        f(i-1,j,grid,vis);
        f(i+1,j,grid,vis);
        f(i,j-1,grid,vis);  
        f(i,j+1,grid,vis);
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
        int c=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1'&&vis[i][j]==0)
                {
                    c++;
                    f(i,j,grid,vis);
                }
            }
        }
        return c;
    }
};
