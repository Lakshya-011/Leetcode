class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n =  nums.size() ;
        for(int i=0;i<n;i++){
            int d=0;
            int val=nums[i];
            while(val!=0){
                d+=val%10;
                val=val/10;
            }
            if(d==i)
            return i;
        }
        return -1;
    }
};