class Solution {
    void solve(int i,vector<int>& nums, set<vector<int>>& ans){
        if(i>=nums.size()){
            ans.insert(nums);
            return;
        }
        for(int j=i;j<nums.size();j++){
            swap(nums[i],nums[j]);
            solve(i+1,nums,ans);
            swap(nums[i],nums[j]);
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> ans;
        solve(0,nums,ans);
        return vector(ans.begin(),ans.end());
    }
};