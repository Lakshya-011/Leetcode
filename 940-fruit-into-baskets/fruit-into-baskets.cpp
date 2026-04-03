class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int s=0;
        int maxi=0;
        unordered_map<int,int> mp;
        for(int i=0;i<fruits.size();i++){
            mp[fruits[i]]++;

            while(mp.size()>2){
                mp[fruits[s]]--;
                if(mp[fruits[s]]==0)
                mp.erase(fruits[s]);

                s++;
            }
            maxi=max(maxi,i-s+1);
        }
        return maxi;
    }
};