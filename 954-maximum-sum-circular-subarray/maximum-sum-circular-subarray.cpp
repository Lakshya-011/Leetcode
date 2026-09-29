class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total=0, mxsum=INT_MIN, mnsum=INT_MAX; int c1=0,c2=0;
        for(int x:nums){
            total+=x;
            c1+=x;
            mxsum=max(mxsum,c1);
            if(c1<0)
            c1=0;
            c2+=x;
            mnsum=min(c2,mnsum);
            if(c2>0)
            c2=0;
        }
        if(total==mnsum)
        return mxsum;
        else
        return max(mxsum,total-mnsum);
    }
};