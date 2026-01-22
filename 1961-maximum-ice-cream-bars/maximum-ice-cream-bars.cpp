class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        // map<int,int> mp;

        // for(int i:costs){
        //     mp[i]++;
        // }
        // int c=0;
        // for(auto &it:mp){
        //     if(it.first>coins)
        //     break;
        //     int first=it.first;
        //     int freq=it.second;
        //     while(freq>0 && first <= coins){
        //         coins=coins-first;
        //         c++;
        //         freq--;
        //     }
        // }
        // return c;
        int maxi=INT_MIN;
        for(int i=0;i<costs.size();i++){
            maxi=max(maxi,costs[i]);
        }
        int c=0;
        vector<int> freq(maxi+1,0);

        for(int i=0;i<costs.size();i++){
            freq[costs[i]]++;
        }

        for(int i=1;i<freq.size();i++){
            if(freq[i]==0)
            continue;

            int buy=min(freq[i],coins/i);
            c=c+buy;
            coins=coins-i*buy;
        }
        return c;
    }
};