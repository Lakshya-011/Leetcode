class Solution {
public:
    int binaryGap(int n) {
        int i=0;
        while(n>0){
            int bit=n&1;
            if(bit==1){
                break;
            }
            n=n>>1;
        }
        int maxi=0;
        int cnt=1;
        while(n>0){
            n=n>>1;
            int bit=n&1;
            if(n>0 && bit==0){
                cnt++;
            }
            else if(bit==1){
                maxi=max(maxi,cnt);
                cnt=1;
            }
            else
            break;
        }
        return maxi;
    }
};