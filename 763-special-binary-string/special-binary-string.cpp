class Solution {
public:
    string makeLargestSpecial(string s) {
        int cnt=0;
        int i=0;
        vector<string> res;
        for(int j=0;j<s.length();j++){
            cnt+=(s[j] == '1') ? 1 : -1;

            if(cnt==0){
                res.push_back('1' + makeLargestSpecial(s.substr(i+1,j-i-1)) +'0');
                i=j+1;
            }
        }
        sort(res.begin(),res.end(),greater<string>());
        string ans;
        for(const string temp:res){
        ans+=temp;
        }
        return ans;
    }
};