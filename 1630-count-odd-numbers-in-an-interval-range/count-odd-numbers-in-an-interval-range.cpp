class Solution {
public:
    int countOdds(int low, int high) {
        int c=0;
        for(int i=low;i<=high;i++){
            if(i%2!=0)
            c++;
        }
        return c;

        // int ans=high-low+1;
        // if(ans%2==0)
        // return ans/2;

        // else{
        //     if(low%2==0 && high%2==0)
        //     return ans/2;
        //     else
        //     return ans/2 +1;
        // }
    }
};