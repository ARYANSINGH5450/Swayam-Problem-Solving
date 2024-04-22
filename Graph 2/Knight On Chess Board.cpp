int f(queue<pair<pair<int,int>,int>>& q,vector<vector<int>>& vis,int A,int B,int E,int F)
{
    while(!q.empty())
    {
        int i=q.front().first.first;
        int j=q.front().first.second;
        int moves=q.front().second;
        if(i==E-1&&j==F-1)
        {
            return moves;
        }
        if(i-2>=0&&j+1<B&&vis[i-2][j+1]==0)  q.push({{i-2,j+1},moves+1}); vis[i-2][j+1]=1;
        if(i-2>=0&&j-1>=0&&vis[i-2][j-1]==0)  q.push({{i-2,j-1},moves+1}); vis[i-2][j-1]=1;
        if(i-1>=0&&j-2>=0&&vis[i-1][j-2]==0)  q.push({{i-1,j-2},moves+1}); vis[i-1][j-2]=1;
        if(i-1>=0&&j+2<B&&vis[i-1][j+2]==0)  q.push({{i-1,j+2},moves+1}); vis[i-1][j+2]=1;
        if(i+2<A&&j+1<B&&vis[i+2][j+1]==0)  q.push({{i+2,j+1},moves+1}); vis[i+2][j+1]=1;
        if(i+2<A&&j-1>=0&&vis[i+2][j-1]==0)  q.push({{i+2,j-1},moves+1}); vis[i+2][j-1]=1;
        if(i+1<A&&j+2<B&&vis[i+1][j+2]==0)  q.push({{i+1,j+2},moves+1}); vis[i+1][j+2]=1;
        if(i+1<A&&j-2>=0&&vis[i+1][j-2]==0)  q.push({{i+1,j-2},moves+1}); vis[i+1][j-2]=1;
        q.pop();
    }
    return -1;
}
int Solution::knight(int A, int B, int C, int D, int E, int F) {
    vector<vector<int>>vis(A,vector<int>(B,0));
    queue<pair<pair<int,int>,int>>q;
    q.push({{C-1,D-1},0});
    vis[C-1][D-1]=1;
    return f(q,vis,A,B,E,F);
}
