class Solution {
public:
    int f(string s,int i,vector<int> &dp){
        if(i==s.length()) return 1;
        if(dp[i]!=-1) return dp[i];
        if(s[i]=='0') return dp[i]=0;
        int l=f(s,i+1,dp);
        string st;
        st+=s[i];
        st+=s[i+1];
        if(i+1!=s.length()&&stoi(st)<=26)
        {
            l+=f(s,i+2,dp);
        }
        return dp[i]=l;
    }
    int numDecodings(string s) {
        vector<int>dp(s.length()+1,-1);
        return f(s,0,dp);
    }
};
