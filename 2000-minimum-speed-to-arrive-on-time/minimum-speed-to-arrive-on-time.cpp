class Solution {
    private:
    bool check(vector<int>& dist,int speed, double hour){
        double ans=0;
        for(int i=0;i<dist.size();i++){
            double d=dist[i]*1.0/speed;
            if(i!=dist.size()-1)
            ans+=ceil(d);
            else
            ans+=d;

            if(ans>hour)
            return false;
        }
        if(ans<=hour)
        return true;

        return false;
    }
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l=1;
        int h=1e7;
        int ans=-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(check(dist,mid,hour)){
                ans=mid;
                h=mid-1;
            }
            else
            l=mid+1;
        }
        return ans;
    }
};