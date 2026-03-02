class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int tswap=0;
        int n=grid.size();
        vector<int> a(n,0);
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=n-1;j>=0;j--){
                if(grid[i][j]==1)
                break;
                else
                cnt++;
            }
            a[i]=cnt;
        }
        for(int i=0;i<n;i++){
            int need=n-i-1;
            int j=i;
            while(j<n && a[j]<need){
                j++;
            }
            if(j==n)
            return -1;

            tswap+=j-i;

            while(j>i){
                swap(a[j],a[j-1]);
                j--;
            }
        }
        return tswap;
    }
};