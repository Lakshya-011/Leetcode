class Solution {
    private:
    int solve(vector<int>& num){
        int n=num.size();
        int prev1=0;
        int prev2=num[0];
        
        for(int i=1;i<n;i++){
            int incl=prev1+num[i];
            int excl=prev2+0;
            int ans=max(incl,excl);
            prev1=prev2;
            prev2=ans;
        }
        return prev2;
    }
public:
    int rob(vector<int>& nums) {
        vector<int> v1,v2;
        if(nums.size()==1)
        return nums[0];
        for(int i=0;i<nums.size();i++){
            if(i!=nums.size()-1)
            v1.push_back(nums[i]);
            if(i!=0)
            v2.push_back(nums[i]);
        }
        return max(solve(v1),solve(v2));
    }
};