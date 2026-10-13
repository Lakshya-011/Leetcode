class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<0)
            nums[i]=-1*nums[i];
        }
        sort(nums.begin(),nums.end());
        for(int i=n-1;i>=n/2;i--){
            ans+=1LL*(nums[i]*nums[i]);
        }
        for(int i=0;i<n/2;i++){
            ans=ans-1LL*(nums[i]*nums[i]);
        }
        return ans;
    }
};