class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
    int cnt=0;
    sort(costs.begin(),costs.end());
    int n=costs.size();
    for(int i=0;i<n;i++){
        if(coins<costs[i])
        break;

        else{
            coins-=costs[i];
            cnt++;
            }
        }
        return cnt;
    }
};