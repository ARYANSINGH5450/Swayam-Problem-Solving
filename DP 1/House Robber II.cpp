class Solution {
public:
//Recursion For House Robber I
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
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
        {
            return nums[0];
        }
        if(n==2)
        {
            return max(nums[0],nums[1]);
        }
        vector<int>dp1(n-1);
        vector<int>dp2(n-1);
        dp1[0]=nums[0];
        dp1[1]=max(nums[0],nums[1]);
        int take,ntake;
        for(int i=2;i<n-1;i++)
        {
            take=nums[i]+dp1[i-2];
            ntake=0+dp1[i-1];
            dp1[i]=max(take,ntake);
        }
        dp2[0]=nums[1];
        dp2[1]=max(nums[1],nums[2]);
        int j=2;
        for(int i=3;i<n;i++)
        {
            take=nums[i]+dp2[j-2];
            ntake=0+dp2[j-1];
            dp2[j]=max(take,ntake);
            j++;
        }
        return max(dp1[n-2],dp2[n-2]);
    }
};
