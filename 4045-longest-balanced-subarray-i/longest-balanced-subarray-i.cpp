class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            set<int> ecount;
            set<int> ocount;
            for(int j=i;j<n;j++){
                if(nums[j]%2==0)
                ecount.insert(nums[j]);
                else
                ocount.insert(nums[j]);

                if(ecount.size()==ocount.size())
                maxi=max(maxi,j-i+1);
            }
        }
        return maxi;
    }
};