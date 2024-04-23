bool incircle(int x,int y,vector<int> &E, vector<int> &F,int C,int D)
{
    for(int i=0;i<C;i++)
    {
        int cx=E[i];
        int cy=F[i];
        int d=((cx-x)*(cx-x))+((cy-y)*(cy-y));
        if(d<=D*D)
        {
            return true;
        }
    }
    return false;
}
bool f(int i,int j,int A, int B, int C, int D, vector<int> &E, vector<int> &F,vector<vector<int>>& vis)
{
    if(i<0||j<0||i>A||j>B||incircle(i,j,E,F,C,D)||vis[i][j]==1)
    {
        return false;
    }
    if(i==A&&j==B)
    {
        return true;
    }
    vis[i][j]=1;
    if(f(i+1,j,A,B,C,D,E,F,vis)) return true;
    if(f(i,j+1,A,B,C,D,E,F,vis)) return true;
    if(f(i-1,j,A,B,C,D,E,F,vis)) return true;
    if(f(i,j-1,A,B,C,D,E,F,vis)) return true;
    if(f(i+1,j-1,A,B,C,D,E,F,vis)) return true;
    if(f(i-1,j+1,A,B,C,D,E,F,vis)) return true;
    if(f(i+1,j+1,A,B,C,D,E,F,vis)) return true;
    if(f(i-1,j-1,A,B,C,D,E,F,vis)) return true;
    return false;
}
string Solution::solve(int A, int B, int C, int D, vector<int> &E, vector<int> &F) {
    vector<vector<int>>vis(A+1,vector<int>(B+1,0));
    if(f(0,0,A,B,C,D,E,F,vis))
    {
        return "YES";
    }
    return "NO";
}
