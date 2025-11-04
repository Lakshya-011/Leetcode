class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size();
        int c=matrix[0].size();

        int rindex=0;
        int cindex=c-1;

        while(rindex<r && cindex>=0){
            int e=matrix[rindex][cindex];
            if(e==target)
            return 1;

            if(e<target)
            rindex++;

            else
            cindex--;
        }
        return 0;
    }
};