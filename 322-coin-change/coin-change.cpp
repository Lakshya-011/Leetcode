class Solution {
public:
    int solve(vector<int>& dp,int n,vector<int>& coins,int amount){
        if(amount==0)
        return 0;

        if(amount<0)
        return INT_MAX;
        if(dp[amount]!=-1)
        return dp[amount];
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            int ans=solve(dp,n,coins,amount-coins[i]);
            if(ans!=INT_MAX)
            mini=min(mini,1+ans);
        }
        dp[amount]=mini;
        return dp[amount];
    }
    int coinChange(vector<int>& coins, int amount){
        int n=coins.size();
        vector<int>dp(amount+1,-1);
        int res=solve(dp,n,coins,amount);
        
        if(res==INT_MAX) 
        return -1;
        else
        return res;       
    }
};