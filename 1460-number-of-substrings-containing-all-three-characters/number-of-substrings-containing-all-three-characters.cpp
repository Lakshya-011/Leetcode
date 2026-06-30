class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length();
        vector<int> temp(3,0);
        int l=0;
        int ans=0;
        int r=0;
        while(r<n){
            temp[s[r]-'a']++;
            while(temp[0] > 0 && temp[1] > 0 && temp[2]>0){
                ans+=n-r;
                temp[s[l]-'a']--;
                l++;
            }
            r++;
        }
        return ans;
    }
};