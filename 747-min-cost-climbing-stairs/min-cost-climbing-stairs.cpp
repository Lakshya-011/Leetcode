class Solution {
public:
    int solve(vector<int>& dp,vector<int>& cost,int i){
        if(i==0)
        return cost[0];
        if(i==1)
        return cost[1];
        if(dp[i]!=-1)
        return dp[i];
        dp[i]= min(solve(dp,cost,i-1),solve(dp,cost,i-2))+cost[i];
        return dp[i];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int i=cost.size();
        vector<int> dp(i+1,-1);
        int ans=min(solve(dp,cost,i-1),solve(dp,cost,i-2));
        return ans;
    }
};