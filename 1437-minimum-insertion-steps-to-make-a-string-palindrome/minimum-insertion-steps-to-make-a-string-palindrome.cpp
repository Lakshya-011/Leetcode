class Solution {
public:
    // int lcs(int idx1,string s,int idx2,string t,vector<vector<int>>& dp){
    //     if(idx1<0 || idx2<0) return 0;
    //     if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
    //     if(s[idx1]==t[idx2]) return dp[idx1][idx2]= 1+lcs(idx1-1,s,idx2-1,t,dp);

    //     return dp[idx1][idx2]= max(lcs(idx1-1,s,idx2,t,dp),lcs(idx1,s,idx2-1,t,dp));
    // }
    int solve(string s,string t){
        int n=s.length();
        int m=t.length();
        // vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        // return lcs(n,s,m,t,dp);
        vector<int> prev(m+1,0),curr(m+1,0);
        for(int j=0;j<=m;j++) prev[j]=0;
        for(int i=1;i<=n;i++){
            curr[0]=0;
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1])
                curr[j]=1+prev[j-1];
                else
                curr[j]=max(prev[j],curr[j-1]);
            }
            prev=curr;
        }
        return prev[m];
    }
    int minInsertions(string s) {
        string t=s;
        reverse(t.begin(),t.end());
        int len=solve(s,t);
        return s.length()-len;
    }
};