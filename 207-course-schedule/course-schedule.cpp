class Solution {
public:
    bool dfs(int node,vector<vector<int>>& prerequisites, vector<int>& vis,vector<vector<int>>& adj,vector<int>& path){
        vis[node]=1;
        path[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it,prerequisites,vis,adj,path))
                return true;
            } 

            else if(path[it]==1)
            return true;
        }
        path[node]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>> adj(n);
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        vector<int> vis(n,0);
        vector<int> path(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(i,prerequisites,vis,adj,path))
                return false;
            }
        }
        return true;
    }
};