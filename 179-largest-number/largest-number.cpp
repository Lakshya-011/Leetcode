class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> a;
        for(int x:nums){
            a.push_back(to_string(x));
        }

        sort(a.begin(),a.end(), [](const string &a, const string &b){
            return (b+a) < (a+b); 
        });

        if(a[0]=="0")
        return "0";

        string ans="";
        for(auto c:a){
            ans+=c;
        }
        return ans;
    }
};