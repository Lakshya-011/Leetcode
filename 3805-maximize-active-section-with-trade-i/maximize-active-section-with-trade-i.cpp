class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int i=0;
        int ones=0;
        for(char c:s){
            if(c=='1')
            ones++;
        }
        while(s[i]=='1' && i<s.length()){
            i++;
        }
        int ans=ones;
        int c10=0;
        while(i<s.length() && s[i]=='0'){
            c10++;
            i++;
        }
        while(i<s.length()){
            int c1=0;
            while(s[i]=='1' && i<s.length()){
                c1++;
                i++;
            }
            if(c1==0)
            break;

            int c20=0;
            while(s[i]=='0' && i<s.length()){
                c20++;
                i++;
            }
            if(c20==0)
            break;

            ans=max(ans,ones+c10+c20);
            c10=c20;
        }
        return ans;
    }
};