class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        set<int> st;

        long long sum=0;
        long long mx=0;
        int l=0;
        for(int r=0;r<n;r++){
            if(st.find(nums[r])==st.end()){
                st.insert(nums[r]);
                sum+=nums[r];

                if(r-l+1 == k){
                    mx=max(mx,sum);
                    sum-=nums[l];
                    st.erase(nums[l]);
                    l++;
                }
            }
            else{
                while(nums[l]!=nums[r]){
                    sum-=nums[l];
                    st.erase(nums[l]);
                    l++;
                }
                l++;
            }
        }
        return mx;
    }
};