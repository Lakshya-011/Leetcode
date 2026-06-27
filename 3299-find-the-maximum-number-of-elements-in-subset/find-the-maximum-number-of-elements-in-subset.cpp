class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long,int> mp;
        for(int x:nums)
        mp[x]++;
        int ans=0;
        if(mp.count(1)){
            int cnt=mp[1];
            ans=max(ans,(cnt%2==1)?cnt:cnt-1);
        }
        for(auto it:mp){
            if(it.first==1)
            continue;
            long long curr=it.first;
            int len=0;

            while(mp.count(curr)){
                if(mp[curr]>1){
                    len+=2;
                    curr=curr*curr;
                }
                else{
                    len++;
                    break;
                }
            }
            if(len%2==0) len--;
            ans=max(ans,len);
        }
        return ans;
    }
};