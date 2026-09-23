class Solution {
    private:
    void dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& vis,int dr[],int dc[]){
        vis[i][j]=1;
        int n=grid.size();
        int m=grid[0].size();
        for(int k=0;k<4;k++){
            int nr=i+dr[k];
            int nc=j+dc[k];
            if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]==0 && grid[nr][nc]==1)
            dfs(nr,nc,grid,vis,dr,dc);
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        vector<vector<int>> vis(n,vector<int> (m,0));
        for(int i=0;i<n;i++){
            if(vis[i][0]==0 && grid[i][0]==1)
            dfs(i,0,grid,vis,dr,dc);

            if(vis[i][m-1]==0 && grid[i][m-1]==1)
            dfs(i,m-1,grid,vis,dr,dc);
        }

        for(int j=0;j<m;j++){
            if(vis[0][j]==0 && grid[0][j]==1)
            dfs(0,j,grid,vis,dr,dc);

            if(vis[n-1][j]==0 && grid[n-1][j]==1)
            dfs(n-1,j,grid,vis,dr,dc);
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]==0)
                cnt++;
            }
        }
        return cnt;
    }
};