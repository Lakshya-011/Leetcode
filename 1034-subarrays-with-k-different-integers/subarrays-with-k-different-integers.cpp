class Solution {
    int solve(vector<int>& nums,int k){
        if(k==0) return 0;
        unordered_map<int,int> mp;
        int l=0;int cnt=0;
        int n=nums.size();
        int r=0;
        while(r<n){
            mp[nums[r]]++;

            while(mp.size()>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0)
                mp.erase(nums[l]);

                l++;
            }
            cnt+=r-l+1;

            r++;
        }
        return cnt;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int f1=solve(nums,k);
        int f2=solve(nums,k-1);
        return f1-f2;
    }
};