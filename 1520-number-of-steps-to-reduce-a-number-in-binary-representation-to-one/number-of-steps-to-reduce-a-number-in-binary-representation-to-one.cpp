class Solution {
public:
    int numSteps(string s) {
        int cnt=0;
        int c=0;
        for(int i=s.length()-1;i>0;i--){
            int b=(s[i]-'0')+c;

            if(b==1){
                cnt+=2;
                c=1;
            }
            else
            cnt+=1;
        }
        return cnt+c;
    }
};