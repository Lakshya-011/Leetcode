class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int s=0;
        for(int i:nums){
            s+=i;
        }
        int lsum=0;
        for(int i=0;i<nums.size();i++){
            if(lsum==s-lsum-nums[i])
            return i;

            lsum+=nums[i];
        }
        return -1;
    }
};