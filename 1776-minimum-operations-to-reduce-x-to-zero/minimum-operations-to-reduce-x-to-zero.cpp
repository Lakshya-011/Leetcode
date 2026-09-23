class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int ans=-1;
        int sum=0;
        for(int val:nums)
        sum+=val;
    
        int k=sum-x;
        if(k<0)return -1;
        int temp=0;
        int l=0;
        for(int r=0;r<nums.size();r++){
            temp+=nums[r];
            while(l<=r && temp>k){
                temp=temp-nums[l];
                l++;
            }
            if(temp==k)
            ans=max(ans,r-l+1);
        }
        return ans==-1?-1:nums.size()-ans;
    }
};