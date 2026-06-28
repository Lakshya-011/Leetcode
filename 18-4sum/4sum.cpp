class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        set<vector<int>> st;
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                long long temp=(long long)target-(long long)nums[i]-(long long)nums[j];
                int l=j+1;
                int h=n-1;
                while(l<h){
                    if(nums[l]+nums[h] < temp)
                    l++;

                    else if(nums[l]+nums[h]>temp)
                    h--;

                    else{
                        st.insert({nums[i],nums[j],nums[l],nums[h]});
                        l++;h--;
                    }
                }
            }
        }
        for(auto it:st){
            ans.push_back(it);
        }
        return ans;
    }
};