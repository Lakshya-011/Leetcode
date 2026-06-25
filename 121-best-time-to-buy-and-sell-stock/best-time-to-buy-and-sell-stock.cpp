class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int temp=prices[0];
        int p=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]<temp)
            temp=prices[i];

            if(prices[i]-temp > p)
            p=prices[i]-temp;
        }
        return p;
    }
};