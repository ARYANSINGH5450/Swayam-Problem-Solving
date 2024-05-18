class Solution {
public:
//Recursion
    /*int f(int i,vector<int>&dp,int n,vector<int>&nums)
    {
        if(i==n-1)
        {
            return nums[i];
        }
        else if(i>=n)
        {
            return 0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        int pick=nums[i]+f(i+2,dp,n,nums);
        int npick=0+f(i+1,dp,n,nums);
        return max(pick,npick);
    }*/
//Bottom-Up
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n);
        dp[0]=nums[0];
        int take,ntake;
        for(int i=1;i<n;i++)
        {
            take=nums[i];
            if(i>1)
            {
                take+=dp[i-2];
            }
            ntake=0+dp[i-1];
            dp[i]=max(take,ntake);
        }
        return dp[n-1];
        
    }
};
