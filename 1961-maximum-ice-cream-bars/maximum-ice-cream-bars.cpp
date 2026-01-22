class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        map<int,int> mp;

        for(int i:costs){
            mp[i]++;
        }
        int c=0;
        for(auto &it:mp){
            if(it.first>coins)
            break;
            int first=it.first;
            int freq=it.second;
            while(freq>0 && first <= coins){
                coins=coins-first;
                c++;
                freq--;
            }
        }
        return c;
    }
};