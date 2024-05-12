class Solution {
public:
    int numSquares(int n) {
        vector<int>v;
        for(int i=1;i<=100;i++)
        {
            v.push_back(i*i);
        }
        vector<int>dp(n+1,INT_MAX);
        dp[0]=0;        
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<v.size();j++)
            {
                if(i-v[j]>=0&&dp[i-v[j]]!=INT_MAX)
                {
                    dp[i]=min(dp[i],1+dp[i-v[j]]);
                }
            }
        }
        return dp[n];
    }
};
