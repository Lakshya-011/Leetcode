class Solution {
    private:
    void solve(int r,int c,int n,int m,vector<vector<int>>& board,vector<vector<int>>& ans){
        int cnt=0;
        if(board[r][c] == 0){
        for(int dr=-1;dr<=1;dr++){
            for(int dc=-1;dc<=1;dc++){
                if(dr==0 && dc==0)
                continue;
                int nr=r+dr;
                int nc=c+dc;
                if(nr>=0 && nr<n && nc>=0 && nc<m && board[nr][nc]==1)
                    cnt++;
                }
            }
            // if(board[r][c]==1)
            // cnt--;
            if(cnt==3)
            ans[r][c]=1;
            else
            ans[r][c]=0;
        }
        else{
            for(int dr=-1;dr<=1;dr++){
            for(int dc=-1;dc<=1;dc++){
                if(dr==0 && dc==0)
                continue;
                int nr=r+dr;
                int nc=c+dc;
                if(nr>=0 && nr<n && nc>=0 && nc<m && board[nr][nc]==1)
                    cnt++;
                }
            }
            // if(board[r][c]==1)
            // cnt--;
            if(cnt==2 || cnt==3)
            ans[r][c]=1;
            else
            ans[r][c]=0;
        }
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>> ans(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                solve(i,j,n,m,board,ans);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                board[i][j]=ans[i][j];
            }
        }
    }
};