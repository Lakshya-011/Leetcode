class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        if(nums.size()<=2)
        return nums.size();

        int idx1,idx2;
        int mx=*max_element(nums.begin(),nums.end());
        int mi=*min_element(nums.begin(),nums.end());

        for(int i=0;i<nums.size();i++){
            if(nums[i]==mx)
            idx1=i;

            if(nums[i]==mi)
            idx2=i;
        }
        int n=nums.size();
        if(idx2>idx1)
        swap(idx2,idx1);

        return min(((n-idx1)+min(idx2+1,idx1-idx2)),((idx2+1)+min(n-idx1,idx1-idx2)));
    }
};