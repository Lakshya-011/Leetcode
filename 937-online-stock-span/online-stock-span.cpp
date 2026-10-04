class StockSpanner {
public:
    // vector<int> ans;
    stack<pair<int,int>> st;
    int idx;
    StockSpanner() {
        idx=-1;
        // st.clear();
    }
    
    int next(int price) {
        int ans;
        idx=idx+1;
        while(!st.empty() && st.top().first<=price)
        st.pop();

        ans=(idx-(st.empty()?-1:st.top().second));

        st.push({price,idx});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */