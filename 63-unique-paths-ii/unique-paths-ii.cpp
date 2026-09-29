class Solution {
    int cnt=0;
    private:
    int solve(int r,int c,int n,int m,vector<vector<int>>& obstacleGrid,vector<vector<int>>& dp){
        if(r==n-1 && c==m-1){
            return 1;
        }
        if(dp[r][c]!=-1) return dp[r][c];
        int nr=r+1;int nc=c;
        int temp=0;
        if(nr<n && nc<m && obstacleGrid[nr][nc]!=1){
            temp+=solve(nr,nc,n,m,obstacleGrid,dp);
        }
        nr=r;
        nc=c+1;
        if(nr<n && nc<m && obstacleGrid[nr][nc]!=1){
            temp+=solve(nr,nc,n,m,obstacleGrid,dp);
        }
        return dp[r][c]=temp;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1 || obstacleGrid[n-1][m-1]==1) return 0;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(0,0,n,m,obstacleGrid,dp);
    }
};