class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        const int MOD=1e9 + 7;
        vector<int> temp;
        for(int i=0;i<n;i++){
            int s=0;
            for(int j=i;j<n;j++){
                s+=nums[j];
                temp.push_back(s);
            }
        }
        sort(temp.begin(),temp.end());
        int res=0;
        for(int i=left-1;i<right;i++){
            res=(res + temp[i]) % MOD;
        }
        return res;
    }
};