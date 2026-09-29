class Solution {
public:
    bool solve(vector<int> &nums , int k, int idx , vector<vector<int>> &dp){
      
      if(idx >= nums.size() || k < 0){
         return false ;
      }

      if(k == 0){
        return true ;
      }

      if(dp[idx][k] != -1){
         
         return dp[idx][k] ;
      }

      //pick
      bool pick = solve(nums, k - nums[idx] , idx+1,dp) ;
      
      
       bool notpick= solve(nums , k , idx+1, dp) ;
      
       dp[idx][k] = pick || notpick ;

      return  dp[idx][k] ;
    }
    bool canPartition(vector<int>& nums) {

        int n=nums.size();
        int sum = 0 ;
       
        for(int i = 0 ; i< n ; i++){
            sum+=nums[i] ;
        }
         vector<vector<int>> dp(n+1 , vector<int>(sum/2+1 ,-1)) ;
        if(sum %2 == 1){
            return false ;
        }
       
       return solve(nums , sum/2 , 0,dp) ;
    }
};