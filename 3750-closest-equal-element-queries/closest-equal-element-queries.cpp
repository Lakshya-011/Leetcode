class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> ans;
        int n=nums.size();
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        for(int q:queries){
            int mini=INT_MAX;
            vector<int>& v=mp[nums[q]];
            if(v.size()==1){
                ans.push_back(-1);
                continue;
            }
            int p=lower_bound(v.begin(),v.end(),q)-v.begin();
            int left=v[(p-1+v.size())%v.size()];
            int d=abs(q-left);
            mini=min(mini,min(d,n-d));

            int right=v[(p+1)%v.size()];
            int d2=abs(q-right);
            mini=min(mini,min(d2,n-d2));

            ans.push_back(mini);
        }
        return ans;
    }
};