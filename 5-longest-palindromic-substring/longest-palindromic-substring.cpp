class Solution {
    private:
    int t[1001][1001];
    bool solve(string &s,int i,int j){
        if(i>=j)
        return 1;

        if(t[i][j]!=-1)
        return t[i][j];

        if(s[i]==s[j])
        return solve(s,i+1,j-1);

        return t[i][j]=0;
    }
public:
    string longestPalindrome(string s) {
        int maxlen=INT_MIN;
        memset(t,-1,sizeof(t));
        int n=s.length();
        int sp=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(solve(s,i,j)==true){
                    if(j-i+1 > maxlen){
                        maxlen=j-i+1;
                        sp=i;
                    }
                }
            }
        }
        return s.substr(sp,maxlen);
    }
};