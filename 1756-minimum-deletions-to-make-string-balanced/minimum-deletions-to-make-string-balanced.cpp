class Solution {
public:
    int minimumDeletions(string s) {
        int b=0;
        int cnt=0;
        for(char c:s){
            if(c=='b')
            b++;
            else
            cnt=min(cnt+1,b);
        }
        return cnt;
    }
};