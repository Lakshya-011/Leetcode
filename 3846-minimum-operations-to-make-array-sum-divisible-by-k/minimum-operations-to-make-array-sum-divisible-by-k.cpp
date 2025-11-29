class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        long long s=0;
        for(int i=0;i<nums.size();i++){
            s+=nums[i];
        }
        int r=s%k;
        if(r==0)
        return 0;
        return r;
    }
};