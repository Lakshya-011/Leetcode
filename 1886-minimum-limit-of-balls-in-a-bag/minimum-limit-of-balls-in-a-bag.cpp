class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l=1;
        int h=0;
        for(int x:nums)
        h=max(x,h);

        while(l<h){
            int mid=l+(h-l)/2;
            int op=0;
            for(int num:nums)
            op+=(num-1)/mid;

            if(op<=maxOperations)
            h=mid;

            else
            l=mid+1;
        }
        return l;
    }
};