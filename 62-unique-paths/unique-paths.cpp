class Solution {
// private:
// bool isSafe(int x,int y,vector<vector<int>> &visited,int m,int n){
//     return (x>=0 && x<m && y>=0 && y<n && visited[x][y]!=1);
// }
// void solve(vector<vector<int>> &visited,int x,int y,int m,int n,int &c){
//     if(x==m-1 && y==n-1){
//         c++;
//         return;
//     }
//     visited[x][y]=1;

//     int newx=x+1;
//     int newy=y;
//     if(isSafe(newx,newy,visited,m,n)){
//         solve(visited,newx,newy,m,n,c);
//     }

//     newx=x;
//     newy=y+1;
//     if(isSafe(newx,newy,visited,m,n)){
//         solve(visited,newx,newy,m,n,c);
//     }

//     visited[x][y]=0;
// }
public:
    int uniquePaths(int m, int n) {
        // int x=0,y=0;
        // vector<vector<int>> visited(m,vector<int>(n));
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         visited[i][j]=0;
        //     }
        // }
        // int c;
        // solve(visited,x,y,m,n,c);
        // return c;

        vector<vector<int>> dp(m,vector<int> (n,1));
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m-1][n-1];
    }
};