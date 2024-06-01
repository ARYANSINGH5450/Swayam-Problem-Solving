class Solution{
public:
int f(int i,int j,int arr[],vector<vector<int>>& dp)
{
    if(i==j)
    {
        return 0;
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int m=INT_MAX;
    for(int k=i;k<j;k++)
    {
        int a=arr[i-1]*arr[k]*arr[j]+f(i,k,arr,dp)+f(k+1,j,arr,dp);
        m=min(m,a);
    }
    return dp[i][j]=m;
}
    int matrixMultiplication(int N, int arr[])
    {
        vector<vector<int>>dp(N,vector<int>(N,-1));
        return f(1,N-1,arr,dp);
    }
};
