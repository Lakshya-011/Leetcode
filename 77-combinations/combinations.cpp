class Solution {
    private:
    void solve(int s,vector<vector<int>>& res,vector<int>& ans,int n,int k){
        if(ans.size()==k){
            res.push_back(ans);
            return;
        }
        for(int i=s;i<=n;i++){
            ans.push_back(i);
            solve(i+1,res,ans,n,k);
            ans.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        vector<vector<int>> res;
        solve(1,res,temp,n,k);
        return res;
    }
};