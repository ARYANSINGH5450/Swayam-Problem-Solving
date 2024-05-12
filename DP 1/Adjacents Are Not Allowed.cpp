class Solution{
public:
    int maxSum(int N, vector<vector<int>> mat)
    {
        int p1=max(mat[0][0],mat[1][0]);
        int p2=0;
        for(int i=1;i<N;i++) {
            int temp=max(p1,p2);
            p1=p2+max(mat[0][i],mat[1][i]);
            p2=temp;
        }
        return max(p1,p2);
    }
};
