class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
    int presum=0;
    unordered_map<int,int> mp;
    mp[0]=0;      
    for(int i=0;i<nums.size();i++){
        presum=(presum+nums[i])%k;
        if(mp.find(presum)!=mp.end()){
            if(i+1 - mp[presum] >=2 )
                return true;
        }
            else{
                mp[presum]=i+1;
            }
    }
        return false;
    }
};