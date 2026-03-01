class Solution {
    private:
    void solve(int i, string &s, vector<string> &ans){
        if(i>=s.length()){
            ans.push_back(s);
            return;
        }
        solve(i+1,s,ans);
        s[i]='0';
        solve(i+2,s,ans);
        s[i]='1';
    }
public:
    vector<string> validStrings(int n) {
        vector<string> ans;
        string s(n,'1');
        solve(0,s,ans);
        return ans;
    }
};