class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // sort(piles.begin(),piles.end());
        int maxi=piles[0];
        for(int i:piles){
            if(i>maxi)
            maxi=i;
        }
        int i=1;
        int j=maxi;
        int ans=j;
        while(i<=j){
            int mid=i+(j-i)/2;
            long long c=0;
            for(int k=0;k<piles.size();k++){
                c+=(piles[k] + mid-1)/mid;
            }
            if(c>h)
            i=mid+1;
            
            else{
                ans=mid;
                j=mid-1;
            }
        }
        return ans;
    }
};