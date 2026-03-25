class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        long long tsum=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                tsum+=grid[i][j];
            }
        }
        if(tsum%2!=0)
        return false;
        long long ans=tsum/2;
        if(n==1){
            long long s=0;
            for(int i=0;i<m-1;i++){
                s+=grid[0][i];
                if(s==ans)
                return true;
            }
        }
        if(m==1){
            long long s=0;
            for(int i=0;i<n-1;i++){
                s+=grid[i][0];
                if(s==ans)
                return true;
            }
        }
        long long sum=0;
        for(int i=0;i<n-1;i++){
            for(int j=0;j<m;j++){
                sum+=grid[i][j];
            }
            if(sum==ans)
            return true;
        }
        sum=0;
        for(int j=0;j<m-1;j++){
            for(int i=0;i<n;i++){
                sum+=grid[i][j];
            }
            if(sum==ans)
            return true;
        }
        return false;
    }
};