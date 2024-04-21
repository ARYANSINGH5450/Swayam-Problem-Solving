class Solution {
public:
    void f(vector<vector<int>>& grid,queue<pair<pair<int,int>,int>>& q,int& t)
    {
       while(!q.empty())
       {
           int r=q.front().first.first;
           int c=q.front().first.second;
           int time=q.front().second;
           if(r+1<grid.size()&&grid[r+1][c]==1)
           {
               q.push({{r+1,c},time+1});
               grid[r+1][c]=0;
           }
           if(r-1>=0&&grid[r-1][c]==1)
           {
               q.push({{r-1,c},time+1});
               grid[r-1][c]=0;
           }
           if(c+1<grid[0].size()&&grid[r][c+1]==1)
           {
               q.push({{r,c+1},time+1});
               grid[r][c+1]=0;
           }
           if(c-1>=0&&grid[r][c-1]==1)
           {
               q.push({{r,c-1},time+1});
               grid[r][c-1]=0;
           }
           t=max(t,q.front().second);
           q.pop();
       }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int t=0;
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},t});
                }
            }
        }
        f(grid,q,t);
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==1)
                {
                    return -1;
                }
            }
        }
        return t;
    }
};
