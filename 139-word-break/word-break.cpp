class Solution {
    // private:
    // bool solve(int idx,vector<string>& wordDict,string s,vector<int>& dp){
    //     if(idx>=s.length()){
    //         return true;
    //     }
    //     if(dp[idx]!=-1) return dp[idx];
    //     for(string w:wordDict){
    //         int l=w.length();
    //         if(idx+l<=s.length() && s.substr(idx,l)==w){
    //             if(solve(idx+l,wordDict,s,dp))
    //             return dp[idx]=true;
    //         }
    //     }

    //     return dp[idx]=false;
    // }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();
        // vector<int> dp(n,-1);
        // return solve(0,wordDict,s,dp);
        vector<bool> dp(n+1,false);
        dp[0]=true;
        for(int i=1;i<=n;i++){
            for(string w:wordDict){
                int idx=i-w.length();
                if(idx>=0 && dp[idx] && s.substr(idx,w.length())==w){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};