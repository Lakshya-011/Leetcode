class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
       int i=0;
       int j=0;
       long long ans=0;
       int n=nums.size();
       multiset<int> st;
       while(j<n){
        st.insert(nums[j]);
        while((*st.rbegin() - *st.begin()) * 1LL * st.size() > k){
            st.erase(st.find(nums[i]));
            i++;
        }
        ans=ans+(j-i+1);
        j++;
       }
       return ans;
    }
};