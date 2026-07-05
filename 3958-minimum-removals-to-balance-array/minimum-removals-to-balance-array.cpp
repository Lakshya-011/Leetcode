class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int i=0;int j=0;
        int maxi=0;
        while(i<n){
            while((long long)nums[i] > (long long)nums[j]*k){
                j++;
            }
            i++;
            maxi=max(maxi,i-j);
        }
        return n-maxi;
    }
};