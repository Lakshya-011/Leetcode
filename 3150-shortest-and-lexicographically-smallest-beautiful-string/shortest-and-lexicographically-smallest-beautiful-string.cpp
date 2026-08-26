class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector<int> a;
        for(int i=0;i<s.length();i++){
            if(s[i]=='1')
            a.push_back(i);
        }

        if(a.size()<k)
        return "";

        string ans="";
        for(int i=0;i+k-1<a.size();i++){
            int st=a[i];
            int e=a[i+k-1];

            string r= s.substr(st,e-st+1);
            if(ans == "" || r.size()<ans.size() || (r.size()==ans.size() && r<ans))
            ans=r;
        }
        return ans;
    }
};