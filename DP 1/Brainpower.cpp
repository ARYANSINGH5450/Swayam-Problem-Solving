class Solution {
public:
    long long f(vector<vector<int>>& questions,int i,vector<long long>& dp)
    {
        if(i>=questions.size())
        {
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        long long a=questions[i][0]+f(questions,i+questions[i][1]+1,dp);
        long long b=f(questions,i+1,dp);
        return dp[i]=max(a,b);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long>dp(questions.size()+1,-1);
        return f(questions,0,dp);
    }
};
