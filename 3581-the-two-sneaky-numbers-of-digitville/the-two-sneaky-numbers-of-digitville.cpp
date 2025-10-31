class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i:nums){
            mp[i]++;
        }
        vector<int> temp;
        for(auto it: mp){
            if(it.second>1)
            temp.push_back(it.first);
        }
        return temp;
    }
};