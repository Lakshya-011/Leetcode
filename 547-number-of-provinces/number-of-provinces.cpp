class Solution {
    private:
    void dfs(int node,vector<vector<int>>& isConnected, int vis[]){
        vis[node]=1;
        for(int i=0;i<isConnected.size();i++){
            if(isConnected[node][i]==1 && !vis[i])
            dfs(i,isConnected,vis);
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int vis[200]={0};
        int ans=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,isConnected,vis);
                ans++;
            }
        }
        return ans;
    }
};