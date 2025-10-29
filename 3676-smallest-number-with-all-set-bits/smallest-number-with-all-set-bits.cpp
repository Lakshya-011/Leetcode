class Solution {
public:
    int smallestNumber(int n) {
        for(int i=n;i<INT_MAX;i++){
            int x=i;
            int ans=true;
            while(x!=0){
                if((x&1)==0){
                ans=false;
                break;
                }
                x=x>>1;
            }
            if(ans){
                return i;
            }
        }
        return -1;
    }
};