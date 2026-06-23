class Solution {
    private:
    bool check(vector<int>& quantities,int mid,int n){
        int ans=0;
        for(int i=0;i<quantities.size();i++){
            ans+=quantities[i]/mid;
            if(quantities[i]%mid)
            ans++;
            if(ans>n)return false;
        }
        return ans<=n;
    }
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l=1;
        int h=*max_element(quantities.begin(),quantities.end());
        while(l<=h){
            int mid=l+(h-l)/2;
            if(check(quantities,mid,n)){
                h=mid-1;
            }
            else
            l=mid+1;
        }
        return l;
    }
};