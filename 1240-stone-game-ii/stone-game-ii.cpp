class Solution {
public:
int dp[2][101][101];
int solve(int per,int i,vector<int>& p,int m,int n){
    if(i>=n)
    return 0;
    if(dp[per][i][m]!=-1)
    return dp[per][i][m];
    int st=0;
    int res = (per==1) ? -1:INT_MAX;
    for(int x=1;x<=min(2*m,n-i);x++){
        st+=p[i+x-1];

        if(per==1)
        res=max(res,st+solve(0,i+x,p,max(m,x),n));
        else
        res=min(res,solve(1,i+x,p,max(m,x),n));
    }
    return dp[per][i][m]=res;
}
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        memset(dp,-1,sizeof(dp));
        return solve(1,0,piles,1,n);
    }
};