class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int r=grid.size();
        int c=grid[0].size();

        vector<int> rx(c,0);
        vector<int> ry(c,0);

        int res=0;
        for(int i=0;i<r;i++){
            int cx=0;
            int cy=0;

            for(int j=0;j<c;j++){
                if(grid[i][j]=='X')
                cx++;
                else if(grid[i][j]=='Y')
                cy++;

                rx[j] +=cx;
                ry[j] +=cy;

                if(rx[j]==ry[j] && rx[j]>0)
                res++;
            }
        }
        return res;
    }
};