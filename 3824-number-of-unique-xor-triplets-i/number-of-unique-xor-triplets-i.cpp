class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        if(n<=2)
        return n;

        int m=0;
        for(int x:nums)
        m=m|x;

        return m+1;
    }
};