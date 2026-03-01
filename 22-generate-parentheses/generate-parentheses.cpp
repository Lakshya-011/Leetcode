class Solution {
    private:
    void solve(string res,int o,int c,int n,vector<string> &ans){
        if(res.length()== 2*n){
            ans.push_back(res);
            return;
        }
        if(o<n)
        solve(res+'(',o+1,c,n,ans);
        if(c<o)
        solve(res+')',o,c+1,n,ans);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string res="";
        solve(res,0,0,n,ans);
        return ans;
    }
};