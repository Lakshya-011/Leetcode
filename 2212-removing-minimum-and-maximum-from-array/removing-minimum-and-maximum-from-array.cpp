class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        if(nums.size()==1)
        return 1;
        int n=nums.size();
        int x = *max_element(nums.begin(), nums.end());
        int y = *min_element(nums.begin(), nums.end());

        int maxi = find(nums.begin(), nums.end(), x) - nums.begin();
        int mini = find(nums.begin(), nums.end(), y) - nums.begin();

        int c1 = max(maxi, mini) + 1;
        int c2 = n - min(maxi, mini);
        int c3 = (min(maxi, mini) + 1) + (n - max(maxi, mini));

        return min({c1,c2,c3});

    }
};