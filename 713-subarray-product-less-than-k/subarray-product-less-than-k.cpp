class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int cnt=0;
        if(k<=1)
        return 0;
        int p=1;
        int i=0;
        int j=0;
        while(i<nums.size()){
            p=p*nums[i];
            while(j<=i && p>=k){
                p=p/nums[j];
                j++;
            }
            cnt+=i-j+1;
            i++;
        }
        return cnt;
    }
};