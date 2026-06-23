class Solution {
public:
    long long check(vector<int>& time, long long trip){
        long long tt=0;
        for(int x:time){
            long long val=x;
            tt+=(trip/val);
        }
        return tt;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l=1;
        long long h=1LL*(*min_element(time.begin(),time.end()))*totalTrips;
        while(l<h){
            long long mid=l+(h-l)/2;
            if(check(time,mid)>=totalTrips){
                h=mid;
            }
            else
            l=mid+1;
        }
        return l;
    }
};