//Recursion
class Solution {
 public:
     int f(vector<int>&nums,int ind,int prev)
    {
         if(ind>=nums.size()) return 0;
         int a=f(nums,ind+1,prev);
         int b=1+f(nums,ind+1,ind);
         if(prev==-1||nums[ind]>nums[prev]) return max(a,b);
         else return a;
     }
     int lengthOfLIS(vector<int>& nums) {
         return f(nums,0,-1);
     }
 };

//Memoization
class Solution {
public:
    int f(int i,int prev,vector<int>& nums,vector<vector<int>>& dp){
        if(i==nums.size())
            return 0;
        if(dp[i][prev+1]!=-1)
            return dp[i][prev+1];
        int l=0+f(i+1,prev,nums,dp);
        if(prev==-1||nums[i]>nums[prev])
            l=max(l,1+f(i+1,i,nums,dp));
        return dp[i][prev+1]=l;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size()+1,-1));
        return f(0,-1,nums,dp);
    }
};

//Bottom-Up
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
      int ans=1,n=nums.size();
        vector<int>dp(n,1);
        for(int i=1;i<n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(nums[i]>nums[j])
                {
                    dp[i]=max(dp[i],dp[j]+1);
                    ans=max(ans,dp[i]);
                }
            }
        }
        return ans;
    }
};

//Binary Search
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>v;
        for(int i=0;i<n;i++)
        {
            int idx=lower_bound(v.begin(),v.end(),nums[i])-v.begin();
            if(idx==v.size())
            {
                v.push_back(nums[i]);
            }
            else
            {
                v[idx]=nums[i];
            }
        }
        return v.size();
    }
};
