class Solution {
    private:
    vector<int> findpse(vector<int>& heights){
        int n=heights.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=0;i<heights.size();i++){
            while(!st.empty() && heights[st.top()]>=heights[i])
            st.pop();

            ans[i]=(st.empty()?-1:st.top());
            st.push(i);
        }
        return ans;
    }
    vector<int> findnse(vector<int>& heights){
        int n=heights.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i])
            st.pop();

            ans[i]=(st.empty()?n:st.top());
            st.push(i);
        }
        return ans;
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> nse= findnse(heights);
        vector<int> pse=findpse(heights);

        int mx=0;
        for(int i=0;i<heights.size();i++){
            int w1= i-pse[i];
            int w2=nse[i]-i;
            mx=max(mx,heights[i]*(w1+w2-1));
        }
        return mx;
    }
};