class Solution {
    private:
    void solve(vector<int> nums, vector<int> temp, int i,vector<vector<int>>& ans){
        if(i>=nums.size()){
        ans.push_back(temp);
        return;
        }
        solve(nums,temp,i+1,ans);
        int t=nums[i];
        temp.push_back(t);
        solve(nums,temp,i+1,ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>> ans;
       vector<int> temp;
       int i=0;
       solve(nums,temp,i,ans);
       return ans;
    }
};