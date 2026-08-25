class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        set<int> st(nums.begin(),nums.end());
        int num=k;
        while(st.find(num)!=st.end()){
            num+=k;
        }
        
        return num;
    }
};