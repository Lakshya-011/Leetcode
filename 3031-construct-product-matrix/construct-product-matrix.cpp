class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int mod=12345;

        vector<int> temp;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                temp.push_back(grid[i][j]);
            }
        }
        int s=temp.size();
        vector<int> pre(s,1),suf(s,1);
        for(int i=1;i<s;i++){
            pre[i]=(1LL*pre[i-1]*temp[i-1])%mod;
        }
        for(int i=s-2;i>=0;i--){
            suf[i]=(1LL* suf[i+1]*temp[i+1])%mod;
        }
        vector<vector<int>> ans(n,vector<int>(m));
        int k=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[i][j]=(1LL* pre[k]*suf[k])%mod;
                k++;
            }
        }
        return ans;
    }
};