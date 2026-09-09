class Solution {
    private:
    bool check(int i,int j, vector<vector<char>>& grid, vector<vector<int>>& visited){
        if(i<0 || i>grid.size()-1 || j<0 || j>grid[0].size()-1 || grid[i][j]!='1' || visited[i][j]!=0)
        return false;

        return true;
    }
    void bfs(int i,int j, vector<vector<char>>& grid, vector<vector<int>>& visited){
        visited[i][j]=1;
        queue<pair<int,int>> q;
        q.push({i,j});

        int n=grid.size();
        int m=grid[0].size();

        while(!q.empty()){
            int i=q.front().first;
            int j=q.front().second;
            q.pop();
            int ni=i+1;
            int nc=j;
            if(check(ni,nc,grid,visited)){
                visited[ni][nc]=1;
                q.push({ni,nc});
            }

            ni=i-1;
            nc=j;
            if(check(ni,nc,grid,visited)){
                visited[ni][nc]=1;
                q.push({ni,nc});
            }
            ni= i;
            nc=j+1;
            if(check(ni,nc,grid,visited)){
                visited[ni][nc]=1;
                q.push({ni,nc});
            }

            ni=i;
            nc=j-1;
            if(check(ni,nc,grid,visited)){
                visited[ni][nc]=1;
                q.push({ni,nc});
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' && !visited[i][j]){
                    bfs(i,j,grid,visited);
                    ans++;
                }
            }
        }
        return ans;
    }
};