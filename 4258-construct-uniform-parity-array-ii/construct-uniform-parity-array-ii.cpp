class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int o=INT_MAX;
        int e=INT_MAX;
        for(int x:nums1){
            if(x%2==0){
                if(x<e)
                e=x;
            }
            else{
                if(x<o)
                o=x;
            }
        }
        return o==INT_MAX || e>o;
    }
};