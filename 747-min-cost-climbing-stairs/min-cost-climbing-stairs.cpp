class Solution {
public:
    int solve(vector<int>& cost,int n){
        vector<int> dp(n+1);
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int j=2;j<n;j++){
            dp[j]=cost[j]+min(dp[j-1],dp[j-2]);
        }
        return min(dp[n-1],dp[n-2]);
    }
    int minCostClimbingStairs(vector<int>& cost){
        int n=cost.size();
        return solve(cost,n);
    }
};