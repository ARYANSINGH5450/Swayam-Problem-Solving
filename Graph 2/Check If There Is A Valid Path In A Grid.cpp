class Solution {
public:
    bool f(vector<vector<int>>& grid,int i,int j,vector<vector<int>>& vis)
    {
        if(i==grid.size()-1&&j==grid[0].size()-1)
        {
            return true;
        }
        if(i<0||i>grid.size()-1||j<0||j>grid[0].size()-1)
        {
            return false;
        }
        if(vis[i][j]==1)
        {
            return false;
        }
        vis[i][j]=1;
        if(grid[i][j]==1)
        {
            if(j+1<grid[0].size()&&(grid[i][j+1]==1||grid[i][j+1]==3||grid[i][j+1]==5)&&f(grid,i,j+1,vis)||j-1>=0&&(grid[i][j-1]==1||grid[i][j-1]==4||grid[i][j-1]==6)&&f(grid,i,j-1,vis)) return true;
        }
        else if(grid[i][j]==2)
        {
            if(i-1>=0&&(grid[i-1][j]==2||grid[i-1][j]==3||grid[i-1][j]==4)&&f(grid,i-1,j,vis)||i+1<grid.size()&&(grid[i+1][j]==2||grid[i+1][j]==5||grid[i+1][j]==6)&&f(grid,i+1,j,vis)) return true;
        }
        else if(grid[i][j]==3)
        {
            if(j-1>=0&&(grid[i][j-1]==1||grid[i][j-1]==4||grid[i][j-1]==6)&&f(grid,i,j-1,vis)||i+1<grid.size()&&(grid[i+1][j]==2||grid[i+1][j]==5||grid[i+1][j]==6)&&f(grid,i+1,j,vis)) return true;
        }
        else if(grid[i][j]==4)
        {
            if(j+1<grid[0].size()&&(grid[i][j+1]==1||grid[i][j+1]==3||grid[i][j+1]==5)&&f(grid,i,j+1,vis)||i+1<grid.size()&&(grid[i+1][j]==2||grid[i+1][j]==5||grid[i+1][j]==6)&&f(grid,i+1,j,vis)) return true;
        }
        else if(grid[i][j]==5)
        {
            if(i-1>=0&&(grid[i-1][j]==2||grid[i-1][j]==3||grid[i-1][j]==4)&&f(grid,i-1,j,vis)||j-1>=0&&(grid[i][j-1]==1||grid[i][j-1]==4||grid[i][j-1]==6)&&f(grid,i,j-1,vis)) return true;
        }
        else if(grid[i][j]==6)
        {
            if(i-1>=0&&(grid[i-1][j]==2||grid[i-1][j]==3||grid[i-1][j]==4)&&f(grid,i-1,j,vis)||j+1<grid[0].size()&&(grid[i][j+1]==1||grid[i][j+1]==3||grid[i][j+1]==5)&&f(grid,i,j+1,vis)) return true;
        }
        return false;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        vector<vector<int>>vis(grid.size(),vector<int>(grid[0].size(),0));
        return f(grid,0,0,vis);
    }
};
