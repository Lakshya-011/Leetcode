class Solution {
    int n,m;
    private:
    void dfs(int r,int c,vector<vector<char>>& board, vector<vector<int>>& vis){
        vis[r][c]=1;
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];

            if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]==0 && board[nr][nc]=='X')
            dfs(nr,nc,board,vis);
        }
    }
public:
    int countBattleships(vector<vector<char>>& board) {
        n=board.size();
        m=board[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j]=='X'){
                    dfs(i,j,board,vis);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};