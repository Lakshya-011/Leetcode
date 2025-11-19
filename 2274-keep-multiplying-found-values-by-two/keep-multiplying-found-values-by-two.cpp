class Solution {
    private:
    bool check(vector<int>& nums,int original){
        for(int i=0;i<nums.size();i++){
            if(nums[i]==original)
            return true;
        }
        return false;
    }
public:
    int findFinalValue(vector<int>& nums, int original) {
        int n=nums.size();
        int c=0;
        while(check(nums,original)){
            original=original*2;
        }
        return original;
    }
};