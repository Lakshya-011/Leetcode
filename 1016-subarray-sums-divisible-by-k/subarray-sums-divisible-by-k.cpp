class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int c=0;int psum=0;
        unordered_map<int,int> mp;
        mp[0]=1;
        for(int i=0;i<nums.size();i++){
            psum+=nums[i];
            int rem=psum%k;

            if(rem<0)
            rem+=k;

            if(mp.count(rem))
            c+=mp[rem];

            mp[rem]++;
        }
        return c;
    }
};