class Solution {

    private:
    int diff(vector<int>& nums,int l,int r,vector<vector<int>>& dp){
        if(l==r)
        return nums[l];
        if(dp[l][r]!=-1)
        return dp[l][r];
        int pickleft= nums[l]-diff(nums,l+1,r,dp);
        int pickright=nums[r]-diff(nums,l,r-1,dp);

        dp[l][r] = max(pickleft,pickright);
        return dp[l][r];
    }
public:
    bool predictTheWinner(vector<int>& nums) {
    int n=nums.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    int ans=diff(nums,0,n-1,dp);
    return ans>=0;
    }
};