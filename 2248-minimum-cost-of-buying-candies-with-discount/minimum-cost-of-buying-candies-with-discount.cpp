class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        int tcost=0;
        for(int i=cost.size()-1;i>=0;i-=3){
            tcost+=cost[i];
            if(i-1>=0)
            tcost+=cost[i-1];
        }
        return tcost;
    }
};