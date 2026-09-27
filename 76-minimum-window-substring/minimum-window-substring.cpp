class Solution {
public:
    string minWindow(string s, string t) {

        vector<int> mp(256,0);
        for(char c:t)
        mp[c]++;

        int cnt=0,l=0,r=0,mini=INT_MAX,sidx=-1;
        while(r<s.length()){
            if(mp[s[r]]>0) cnt++;
            mp[s[r]]--;

            while(cnt==t.length()){
                if(r-l+1<mini){
                    mini=r-l+1;
                    sidx=l;
                }
                mp[s[l]]++;
                if(mp[s[l]]>0) cnt--;
                l++;
            }
            r++;
        }
        return sidx==-1? "":s.substr(sidx,mini);
    }
};