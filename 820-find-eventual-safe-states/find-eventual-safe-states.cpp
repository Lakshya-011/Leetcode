class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> odegree(n,0);
        vector<vector<int>> rgraph(n);
        for(int i=0;i<n;i++){
            odegree[i]=graph[i].size();

            for(auto it:graph[i])
            rgraph[it].push_back(i);
        }
        vector<int> ans;
        queue<int> q;
        for(int i=0;i<n;i++){
            if(odegree[i]==0)
            q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);

            for(auto it:rgraph[node]){
                odegree[it]--;
                if(odegree[it]==0)
                q.push(it);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};