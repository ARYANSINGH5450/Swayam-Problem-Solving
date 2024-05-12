class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
         priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>>pq;
        int n=heights.size();
        int m=heights[0].size();
        int dx[4]={0,1,0,-1};
        int dy[4]={1,0,-1,0};
        int dis[n][m];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                dis[i][j]=INT_MAX;
            }
        }
        pq.push({0,{0,0}});
        dis[0][0]=0;
        while(!pq.empty())
        {
            int curr=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();
            if(x==n-1&&y==m-1) return curr;
            for(int i=0;i<4;i++)
            {
                int xx=x+dx[i];
                int yy=y+dy[i];
                if(xx>=0&&yy>=0&&xx<n&&yy<m)
                {
                    int nd=max(curr,abs(heights[xx][yy]-heights[x][y]));
                    if(nd<dis[xx][yy])
                    {
                        dis[xx][yy]=nd;
                        pq.push({nd,{xx,yy}});
                    }
                }
            }
        }
        return 0;
    }
};
