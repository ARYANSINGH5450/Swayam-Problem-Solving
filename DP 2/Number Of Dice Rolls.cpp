class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        int m=1e9+7;
        vector<vector<int>>dp(n+1,vector<int>(target+1));
        dp[0][0]=1;
        for(int i=1;i<n+1;i++) 
        {
            for(int j=i;j<=min(target,k*i);j++) 
            {
                long c=0;
                for(int x=1;x<=min(j,k);x++) 
                {
                    c+=dp[i-1][j-x];
                }
                dp[i][j]=c%m;
            }
        }
        return dp[n][target];
    }
};
