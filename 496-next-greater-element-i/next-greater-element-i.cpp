class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            int val=nums1[i];
            stack<int> st;
            st.push(val);
            int j=0;
            while(j<nums2.size() && nums2[j]!=val)
            j++;
            bool flag=false;
            while(j<nums2.size()){
                if(nums2[j]>val){
                    ans.push_back(nums2[j]);
                    flag=true;
                    break;
                }
                j++;
            }
            if(!flag)
            ans.push_back(-1);
        }
        return ans;
    }
};