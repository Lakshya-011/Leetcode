class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size()<3)
        return false;
        int f=INT_MAX;
        int s=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=f)
            f=nums[i];

            else if(nums[i]<=s)
            s=nums[i];

            else
            return true;
        }
        return false;
    }
};