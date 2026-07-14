class Solution {
    private:
    vector<pair<char,int>> fun1(string s){
        vector<pair<char,int>> temp;
        int i=0;
        while(i<s.length()){
           int cnt=0;
           char ch=s[i];
           while(i<s.length() && s[i]==ch){
            cnt++;
            i++;
           }
            temp.push_back({ch,cnt});
        }
        return temp;
    }
    string fun2(vector<pair<char,int>>& temp){
        string s="";
        for(int i=0;i<temp.size();i++){
            s+=(to_string(temp[i].second));
            s+=(temp[i].first);
        }
        return s;
    }
public:
    string countAndSay(int n) {
        string ans="1";
        for(int i=2;i<=n;i++){
            vector<pair<char,int>> temp=fun1(ans);
            ans=fun2(temp);
        }
        return ans;
    }
};