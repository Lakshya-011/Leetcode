class Solution {
public:
    int numSteps(string s) {
        int ans=0;
        int j=0;
        for(int i=s.length()-1; i>0;i--){
            int bit =(s[i]-'0') + j;

            if(bit==1){
                ans+=2;
                j=1;
            }
            else
            ans+=1;
        }
        return ans+j;
    }
};