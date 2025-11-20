class Solution {
    private:
    int helper(int i,int n,vector<int> &nums,vector<int>& dp){

        if(i>n)
        return 0;

        if(dp[i]!=-1){
            return dp[i];
        }

        int pick=nums[i]+helper(i+2,n,nums,dp);
        int notpick=0+helper(i+1,n,nums,dp);
        return dp[i]=max(pick,notpick);
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
        return nums[0];
        vector<int> dp(n+1,-1);
        vector<int> dp2(n+1,-1);
        int ans=helper(1,n-1,nums,dp);
        int ans2=helper(0,n-2,nums,dp2);
        return max(ans,ans2);
    }
};