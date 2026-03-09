class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows<=1)
        return s;

        vector<string> ans(numRows,"");
        int j=0;
        int d=-1;
        for(int i=0;i<s.length();i++){
            if(j==numRows-1 || j==0)
            d=d*(-1);
            ans[j]+=s[i];
            if(d==1)
            j++;
            else
            j--;
        }
        string res;
        for(auto it:ans)
        res+=it;

        return res;
    }
};