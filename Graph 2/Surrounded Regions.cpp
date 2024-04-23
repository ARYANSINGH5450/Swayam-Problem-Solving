class Solution {
public:
    void f(int i,int j,vector<vector<char>>& board,vector<vector<int>>& vis)
    {
        if(i<0||i>board.size()-1||j<0||j>board[0].size()-1||vis[i][j]==1)
        {
            return;
        }
        if(board[i][j]=='X')
        {
            return;
        }
        vis[i][j]=1;
        board[i][j]='#';
        f(i-1,j,board,vis);
        f(i+1,j,board,vis);
        f(i,j-1,board,vis);  
        f(i,j+1,board,vis);
    }
    void solve(vector<vector<char>>& board) {
        vector<vector<int>>vis(board.size(),vector<int>(board[0].size(),0));
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]=='O'&&vis[i][j]==0&&(i==0||j==0||i==board.size()-1||j==board[0].size()-1))
                {
                    f(i,j,board,vis);
                }
            }
        }
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]=='O')
                {
                    board[i][j]='X';
                }
                if(board[i][j]=='#')
                {
                    board[i][j]='O';
                }
            }
        }
    }
};
