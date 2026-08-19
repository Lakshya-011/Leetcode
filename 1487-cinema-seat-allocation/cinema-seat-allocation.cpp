class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        set<int> s1={2,3,4,5};
        set<int> s2={4,5,6,7};
        set<int> s3={6,7,8,9};
        unordered_map<int,set<int>> mp;
        for(auto seat:reservedSeats){
            mp[seat[0]].insert(seat[1]);
        }
        int ans= (n-mp.size())*2;
        for(auto [row,seats]:mp){
            bool l=true,m=true,r=true;
            for(int seat:seats){
                if(s1.count(seat))
                l=false;

                if(s2.count(seat))
                m=false;

                if(s3.count(seat))
                r=false;
            }
            if(l && r)
            ans+=2;
            else if(l || m || r)
            ans+=1;
        }
        return ans;
    }
};