class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n= grid.size();
        int m=grid[0].size();
        // vector<vector<int>> vis(n,vector<int> (m,0));
        int ans=0;
        int fresh=0;
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    // vis[i][j]=2;
                    q.push({{i,j},ans});
                }
                else{
                    if(grid[i][j]==1)
                    fresh++;
                }
            }
        }
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        while(!q.empty()){
            int i=q.front().first.first;
            int j=q.front().first.second;
            int time=q.front().second;
            q.pop();
            ans=max(ans,time);
            for(int k=0;k<4;k++){
                    int ni= i+dr[k];
                    int nj=j+dc[k];

                    if(ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj]==1){
                        grid[ni][nj]=2;
                q.push({{ni,nj},time+1});
                fresh--;
                }
            }
        }
        if(fresh)
        return -1;
        return ans;
    }
};