class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int mx=nums[0];
        vector<int> pre(nums.size());
        for(int i=0;i<nums.size();i++){
        mx=max(mx,nums[i]);
        pre[i]=__gcd(mx,nums[i]);
        }
        sort(pre.begin(),pre.end());
        int i=0;int j=pre.size()-1;
        long long sum=0;
        while(i<j){
            int r=__gcd(pre[i],pre[j]);
            sum+=r;
            i++;
            j--;
        }
        return sum;
    }
};