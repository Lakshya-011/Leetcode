class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> mp;
        mp[0]=1;
        int s=0;
        int ans=0;
        for(int x:nums){
            s+=x;
            if(mp.find(s-goal)!=mp.end())
            ans+=mp[s-goal];

            mp[s]++;
        }
        return ans;
    }
};