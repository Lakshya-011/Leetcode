class Solution {
public:
    void dfs(int r,int c,vector<vector<int>>& grid,vector<vector<int>>& vis,long long& sum){
        vis[r][c]=1;
        sum+=grid[r][c];
        int dr[]={1,-1,0,0};
        int dc[]={0,0,1,-1};
        for(int i=0;i<4;i++){
            int nr=r+dr[i];
            int nc=c+dc[i];

            if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() && vis[nr][nc]!=1 && 
            grid[nr][nc]!=0){
                dfs(nr,nc,grid,vis,sum);
            }
        }
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0 && vis[i][j]!=1){
                    long long sum=0;
                    dfs(i,j,grid,vis,sum);
                    if(sum%k==0)
                    ans++;
                }
            }
        }
        return ans;
    }
};