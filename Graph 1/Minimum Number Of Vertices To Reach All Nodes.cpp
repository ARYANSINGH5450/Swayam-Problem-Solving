class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>ind(n,0);
        vector<int>v;
        for(auto i:edges)
        {
            ind[i[1]]++;
        }
        for(int i=0;i<n;i++)
        {
            if(ind[i]==0)
            {
                v.push_back(i);
            }
        }
        return v;
    }
};
