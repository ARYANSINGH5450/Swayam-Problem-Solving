class Solution
{
public:
    int countFriendsPairings(int n) 
    { 
        int m=1e9+7;
        long long p1=1,p2=1;
        for(int i=2;i<=n;i++) 
        {
            int ans=(p1+((i-1)*p2)%m)%m;
            p2=p1;
            p1=ans;
        }
        return p1;
    }
};    
