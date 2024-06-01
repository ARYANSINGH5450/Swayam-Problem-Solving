//Memoization

class Solution{
public:
/*  int f(int i,vector<int>coins,int amount,vector<vector<int>>& dp)
    {
        if(i<0)
        {
            return INT_MAX-1;
        }
        if(amount<=0)
        {
            return 0;
        }
        if(dp[i][amount]!=-1)
        {
            return dp[i][amount];
        }
        int res=-1;
        if(coins[i]>amount)
        {
            return dp[i][amount]=f(i-1,coins,amount,dp);
        }
        else
        {
            int a=1+f(i,coins,amount-coins[i],dp);
            int b=0+f(i-1,coins,amount,dp);
            return dp[i][amount]=min(a,b);
        }
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        int ans=f(n-1,coins,amount,dp);
        return (ans==INT_MAX-1)?-1:ans;
        }
   };*/

//Tabulation
    
int f(int n,vector<int>coins,int amount,vector<vector<int>>& dp)
	{
		for(int i=0;i<n+1;i++)
		{
			for(int j=0;j<amount+1;j++)
			{
				if(j==0)
                                {
                                     dp[i][j]=0;
                                }
				if(i==0)
                                {
                                     dp[i][j]=INT_MAX-1;
                                }
			}
		}
		for(int i=1;i<n+1;i++)
		{
			for(int j=1;j<amount+1;j++)
			{
				if(coins[i-1]>j)
                                {
					dp[i][j]=0+dp[i-1][j];
                                 }
				else
                                {
                                        dp[i][j]=min(1+dp[i][j-coins[i-1]],dp[i-1][j]);
                                }
	        	}
		}
		return dp[n][amount];
	}
	int coinChange(vector<int>& coins, int amount) {
		int n=coins.size();
		vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
		int ans=f(n,coins,amount,dp);
		return (ans==INT_MAX-1)?-1:ans;
	}
};
