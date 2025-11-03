class Solution {
public:
    bool solve(vector<int>& weights, int days, int mid){
        int c=1;
        int s=0;
        for(int i=0;i<weights.size();i++){
            if(weights[i]+s<=mid){
                s+=weights[i];
            }
            else{
                c++;
                if(c>days || weights[i]>mid){
                    return false;
                }
                s=weights[i];
            }
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int s=0;
        for(int i:weights){
            s+=i;
        }
        int i=*max_element(weights.begin(),weights.end());
        int j=s;
        int ans=s;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(solve(weights, days, mid)){
                ans=mid;
                j=mid-1;
            }
            else
            i=mid+1;
        }
        return ans;
    }
};