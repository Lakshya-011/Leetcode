class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long l=1;
        long long h=*max_element(candies.begin(),candies.end());
        int sum=0;
        
        int ans=0;
        while(l<=h){
            long long mid=l+(h-l)/2;
            long long cnt=0;
            for(int c:candies)
            cnt+=c/mid;
            if(cnt>=k){
                ans=mid;
                l=mid+1;;
            }
            else
            h=mid-1;
        }
        return ans;
    }
};