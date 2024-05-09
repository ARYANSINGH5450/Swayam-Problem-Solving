class Solution {
public:
    class uni{
        public:
        vector<int>v;
        uni(int n) 
        {
            v=vector<int>(n);
            for (int i=0;i<n;i++) 
            {
                v[i]=i;
            }
        }
        int find(int i) 
        {
            if(i==v[i]) return i;
            return v[i]=find(v[i]);
        }
        void merge(int i,int j) 
        {
            int x=find(i);
            int y=find(j);
            if (x!=y)
            {
                v[x]=y;
            }
        }
    };
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        int len=requests.size();
        uni uf(n);
        vector<bool>ans(len);
        for (int i=0;i<len;i++) 
        {
            int u=requests[i][0];
            int v=requests[i][1];
            int x=uf.find(u);
            int y=uf.find(v);
            if(x==y) 
            {
                ans[i]=true;
                continue;
            }
            bool f=true;
            for(vector<int>& res:restrictions) 
            {
                int r1=uf.find(res[0]);
                int r2=uf.find(res[1]);
                if (r1==x&&r2==y||r1==y&&r2==x) 
                {
                    f=false;
                    break;
                }
            }
            if(f) 
            {
                ans[i]=true;
                uf.merge(u,v);
            }
        }
        return ans;
    }
};
