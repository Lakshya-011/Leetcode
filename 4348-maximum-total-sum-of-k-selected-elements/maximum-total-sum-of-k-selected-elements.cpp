class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(),nums.end());
        int i=nums.size()-1;
        long long sum=0;
        while(k>0 && i>=0){
            if(mul>0){
                sum+=(long long)nums[i]*mul;
                mul--;
                k--;
            }
            else{
                sum+=nums[i];
                k--;
            }
            i--;
        }
        return sum;
    }
};