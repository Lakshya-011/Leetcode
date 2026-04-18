class Solution {
    // private:
    // int solve(vector<int>& nums,int i,int prev){
    //     if(i<0)
    //     return 0;
    //     int pick=0;
    //     int npick=solve(nums,i-1,prev);
    //     if(nums[i]<prev)
    //     pick=1+solve(nums,i-1,nums[i]);
    //     return max(pick,npick);
    // }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        // return solve(nums,n-1,INT_MAX);

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};