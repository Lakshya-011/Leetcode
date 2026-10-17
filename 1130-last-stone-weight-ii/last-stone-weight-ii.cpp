class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n=stones.size();
        long long t=0;
        for(int x:stones)
        t+=x;
        vector<vector<bool>> dp(n,vector<bool>(t+1,0));
        for(int i=0;i<n;i++) dp[i][0]=true;
        if(stones[0]<=t)dp[0][stones[0]]=true;
        for(int idx=1;idx<n;idx++){
            for(int k=1;k<=t;k++){
                bool ntake=dp[idx-1][k];
                bool take=false;
                if(stones[idx]<=k) take=dp[idx-1][k-stones[idx]];
                dp[idx][k]=take||ntake;
            }
        }
        int mini=INT_MAX;
        for(int k=0;k<=t;k++){
            if(dp[n-1][k]==true){
                int diff=abs((2*k)-t);
                mini=min(mini,diff);
            }
        }
        return mini;
    }
};